#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*head=NULL;
struct Node *tail=NULL;

void creat(int arr[],int n)
{
    struct Node *temp,*last;
    head=new struct Node;
    head->data=arr[0];
    head->next=NULL;
    head->prev=NULL;
    last=head;
    tail=last;
    for(int i=1;i<n;i++)
    {
        temp=new struct Node;
        temp->data=arr[i];
        temp->next=NULL;
        temp->prev=last;
        last->next=temp;
        last=temp;
        tail=last;
    }

}


void printforward(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}
 
void printbackward(struct Node *p)
{
    while(tail!=NULL)
    {
        cout<<tail->data<<' ';
        tail=tail->prev;
    }
    cout<<endl;
}
int main()
{
    int arr[]={1,2,3,4,5};
    creat(arr,5);

    printforward(head);
    printbackward(tail);

}
