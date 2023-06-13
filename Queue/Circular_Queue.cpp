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
        front=0;
        rear=0;
        Q=new int[s];
    }

    void enque(int x);
    void deque();
    void print();
    bool isfull();
    bool isempty();
    int frontt();

};
void Queue::print()
{
    // int i=front+1;
    // while(i!=(rear+1)%size)
    // {
    //     cout<<Q[i]<<' ';
    //     i=(i+1)%size;
    // }
    for(int j=front+1;j!=(rear+1)%size;j=(j+1)%size)
    {
        cout<<Q[j]<<' ';
    }
    cout<<endl;
}
void Queue::enque(int x)
{
    if((rear+1)%size==front)
    {
        cout<<"Queue is full"<<endl;
    }
    else 
    {
        rear=(rear+1)%size;
        Q[rear]=x;
        cout<<"Insertion Successful"<<endl;
    }
}

void Queue::deque()
{
    if(rear==front)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        front=(front+1)%size;
        cout<<"Deletion Successful"<<endl;
    }
}

int Queue::frontt()
{
    return Q[front+1];
}

bool Queue::isfull()
{
    return (rear+1)%size==front;
}

bool Queue::isempty()
{
    return rear==front;
}

int main()
{
    cout<<"Enter the size of the Queue You want to create  :";
    int n;
    cin>>n;
    Queue q(n);

    while(1)
    {
        cout<<"Enter 1 for inserting :"<<endl;
        cout<<"Enter 2 for deleting "<<endl;
        cout<<"Enter 3 for displaying the Queue "<<endl;
        cout<<"Enter 4 to check is full "<<endl;
        cout<<"Enter 5 to check is empty "<<endl;
        cout<<"Enter 6 to check the front "<<endl;

        cout<<"Enter Your choice : ";
        char ch;
        cin>>ch;

        if(ch=='1')
        {
            cout<<"Enter a number :";
            int num;
            cin>>num;
            q.enque(num);
        }
        else if(ch=='2')
        {
            q.deque();
        }
        else if(ch=='3')
        {
            q.print();
        }
        else if(ch=='4')
        {
            int k=q.isfull();

            if(k) cout<<"Queue is full "<<endl;
            else cout<<"Queue is not full "<<endl;
        }
        else if(ch=='5')
        {
            int k=q.isempty();

            if(k) cout<<"Queue is empty "<<endl;
            else cout<<"Queue is not empty "<<endl;
        }
        else if(ch=='6')
        {
            int k=q.frontt();
            cout<<"Front is "<<k<<endl;
        }
        else if(ch=='0')
        {
            break;
        }
        else cout<<"WRONG INPUT"<<endl;
    }
}

