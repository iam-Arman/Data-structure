#include<bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front,rear,size;
    int *Q;
public:
    Queue(int s)
    {
        size=s;
        front=-1;
        rear=-1;
        Q=new int[size];
    }

    void enque(int x);
    void deque();
    bool isempty();
    bool isfull();
    void display();


};

void Queue::enque(int x)
{
    if(rear==size-1)
    {
        cout<<"OVERFLOW"<<endl;
    }
    else
    {
        rear++;
        Q[rear]=x;
    }
}

void Queue::deque()
{
    if(rear==front)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    else front++;
}

void Queue::display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    Queue q(5);
    q.enque(19);
    q.enque(10);
    q.enque(5);

    q.display();
    q.deque();
    q.display();
}
