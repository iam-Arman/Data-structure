#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int arr[],int n)
{
   struct Node *temp,*last;
   head=new struct Node;
   head->data=arr[0];
   head->next=NULL;
   last=head;
   for(int i=1;i<n;i++)
   {
        temp=new struct Node;
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
   }
}  

void print(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7};
    create(arr,7);

    print(head);



}
