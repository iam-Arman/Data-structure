#include<bits/stdc++.h>
using namespace std;

class STACKK
{
    public:
    int *A;
    int size;
    int top=-1;

    void PUSH(int value);
    void POP();
    int TOP();
    int isempty();
    int isfull();
    void display();

};

void STACKK::PUSH (int value)
{
    if(top==size-1)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    top++;
    A[top]=value;
}

void STACKK::POP()
{
    if(top==-1)
    {
        cout<<"Stack Underflow"<<endl;
        return;
    }
    top--;
}
void STACKK::display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<A[i]<<' ';
    }
    cout<<endl;
}
int STACKK::isempty()
{
    return top==-1;
}
int STACKK::isfull()
{
    return top==size-1;
}
int main()
{
    int n;
    cout<<"Enter the size of the stack "<<endl;
    cin>>n;
    STACKK st;
    st.A=new int[n];
    st.size=n;
    while(1)
    {
        cout<<" 1 for PUSH "<<endl;
        cout<<" 2 for pop "<<endl;
        cout<<" 3 for display "<<endl;
        cout<<" 4 for is empty "<<endl;
        cout<<"5 for is full"<<endl;
        cout<<" 6 for Exit "<<endl;
        int option ;
        cin>>option;
        if(option==1)
        {
            int x;
            cin>>x;
            st.PUSH(x);
        }
       else if(option ==2)
        {
            st.POP();
        }
        else if(option ==3)
        {
            st.display();
        }
        else if(option ==4)
        {
            int k=st.isempty();
            if(k==1)
            {
                cout<<"Stack is empty"<<endl;
            }
            else cout<<"NOT empty"<<endl;

        }
        else if(option ==5)
        {
            int k=st.isfull();
            if(k==1)
            {
                cout<<"Stack is full"<<endl;
                
            }
            else cout<<"NOT full" <<endl;
        }
        else if(option ==6)
        {
            return 0;
        }
        else 
        cout<<"invalid input"<<endl;  
    }


    cout<<"_________Developed by Shahriar Mahmud Arman_____________"<<endl;
    cout<<"          Email : iamarman252575@gmail.com    "<<endl;
   

}


