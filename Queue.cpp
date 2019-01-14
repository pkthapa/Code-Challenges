#include "main.h"
using namespace std;
#define MAX_SIZE    10
class Queue{
    int top, q_array[MAX_SIZE];
public:
    Queue() : top(0), q_array{0}{}
    void Push(int);
    int Pop();
    bool IsEmpty();
    bool IsFull();
    void Print();
};
//!!-------------------------
void Queue :: Print(){
    for(int i = 0; i < top; i++){
        cout<<q_array[i]<<" ";
    }
    cout<<endl;
}

void Queue :: Push(int value){
    if(IsEmpty()){
        q_array[top++] = value;
        return;
    }

    if(!IsFull()){
        q_array[top++] = value;
    }
    else{
        cout<<"Queue full.\n";
    }
}

int Queue :: Pop(){
    if(!IsEmpty()){
        int popped = q_array[0];

        top--;
        for(int i = 0; i < top; i++){
            q_array[i] = q_array[i + 1];
        }
        return popped;
    }
    else{
        cout<<"Queue is empty.\n";
    }
    return -1;
}

bool Queue :: IsEmpty(){
    return top ? false : true;
}

bool Queue :: IsFull(){
    return (MAX_SIZE <= top) ? true : false;
}

int main()
{
    Queue q;
    q.Push(2);
    q.Push(20);
    q.Push(11);
    q.Push(9);
    q.Push(12);
    q.Print();
    cout<<"Popped = "<<q.Pop()<<endl;
    q.Print();

    q.Push(15);
    q.Print();
    cout<<"Popped = "<<q.Pop()<<endl;
    cout<<"Popped = "<<q.Pop()<<endl;
    cout<<"Popped = "<<q.Pop()<<endl;
    cout<<"Popped = "<<q.Pop()<<endl;
    cout<<"Popped = "<<q.Pop()<<endl;
    cout<<"Popped = "<<q.Pop()<<endl;
    return 0;
}