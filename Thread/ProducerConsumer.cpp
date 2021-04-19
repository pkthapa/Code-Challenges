#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>

using namespace std;

queue<int> q;
mutex mtx;
condition_variable cond;

void producer(int count)
{
    while (count-- > 0)
    {
        unique_lock<mutex> ul(mtx);
        q.push(count);
        cout << __func__ << " produced=" << count << endl;
        ul.unlock();
        cond.notify_one();
        this_thread::sleep_for(chrono::milliseconds(1)); // With this sleep, consumer is allowed to consume what is produced.
    }
}

void consumer()
{
    while (true)
    {
        unique_lock<mutex> ul(mtx);
        cout << __func__ << " waiting..." << endl;
        cond.wait(ul, [](){ return !q.empty(); });
        cout << __func__ << " consumed=" << q.front() << endl;
        q.pop();
        ul.unlock();
    }
}

int main()
{
    thread prod = thread(producer, 10);
    thread cons(consumer);

    prod.join();
    cons.join();
    return 0;
}

/*
Output:
producer produced=9
consumer waiting...
consumer consumed=9
consumer waiting...
producer produced=8
consumer consumed=8
consumer waiting...
producer produced=7
consumer consumed=7
consumer waiting...
producer produced=6
consumer consumed=6
consumer waiting...
producer produced=5
consumer consumed=5
consumer waiting...
producer produced=4
consumer consumed=4
consumer waiting...
producer produced=3
consumer consumed=3
consumer waiting...
producer produced=2
consumer consumed=2
consumer waiting...
producer produced=1
consumer consumed=1
consumer waiting...
producer produced=0
consumer consumed=0
consumer waiting...
*/