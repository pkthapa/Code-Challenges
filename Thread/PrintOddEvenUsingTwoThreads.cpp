#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int number = 0;

void odd()
{
    while(true)
    {
        if (number > 15)
        {
            break;
        }
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, [](){return (number % 2 == 0);});
        number++;
        std::cout << "Thread ID: " << std::this_thread::get_id() << ": " << __func__ << ": " << number << std::endl;
        ul.unlock();
        cv.notify_one();
    }
}
void even()
{
    while(true)
    {
        if (number > 15)
        {
            break;
        }
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, [](){return (number % 2 != 0);});
        number++;
        std::cout << "Thread ID: " << std::this_thread::get_id() << ": " << __func__ << ": " << number << std::endl;
        ul.unlock();
        cv.notify_one();
    }
}

int main(int argc, char** argv)
{
    std::thread t1(odd);
    std::thread t2(even);
    t1.join();
    t2.join();
    return 0;
}