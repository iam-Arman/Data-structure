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
   head=new Node;
   head->data=arr[0];
   head->next=NULL;
   last=head;
   for(int i=1;i<n;i++)
   {
        temp=new Node;
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
   }

   cout<<"Linkedlist created successfully "<<endl<<endl;
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

int count(struct Node *p)
{
    if(p!=NULL) return count(p->next)+1;
    return 0;
}

int sum(struct Node *p)
{
    if(p!=NULL) return sum(p->next)+p->data;
    return 0;
}

int maxele(struct Node *p)
{
    int x=p->data;
    while(p!=NULL)
    {
        if(p->data>x) x=p->data;
        p=p->next;
    }

    return x;
}

string search(struct Node *p,int key)
{
    int i=1;
    while(p!=NULL)
    {
        if(p->data==key) 
        {
            return "FOUND AT position "+to_string(i);
        }
        p=p->next;
        i++;
    }

    return "NOT FOUND";
}
void insert(struct Node *p,int target,int value)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=value;
        head->next=NULL;
        cout<<"Inserted Successfully"<<endl<<endl;
    }
    else if(target==1)
    {
        struct Node *temp;
        temp=new Node;
        temp->data=value;
        temp->next=head;
        head=temp;
        cout<<"Inserted Successfully"<<endl<<endl;
    }
    else if(target<=count(head)+1)
    {
        int k=target-2;
        struct Node *temp;
        temp=p;
        while(k--)
        {
            temp=temp->next;
        }
        struct Node *q=temp->next;

        struct Node *neww=new Node;
        neww->data=value;
        temp->next=neww;
        neww->next=q;
        cout<<"Inserted Successfully"<<endl<<endl;
    }
    else
    {
        cout<<"Invalid Inded "<<endl<<endl;
    }
}

void delet_index(struct Node *p,int index)
{
    if(index==1)
    {
        struct Node *temp=head;
        head=head->next;
        delete temp;
        cout<<"Successfully deleted"<<endl<<endl;
        return;
    }
    else if(index<=count(head)){
    int k=index-1;
    struct Node *temp,*x,*y;
    temp=p;
    while(k--)
    {
        temp=temp->next;
    }
    x=temp->next;
     k=index-2;
     y=p;
    while(k--)
    {
        y=y->next;
    }

    y->next=x;
    delete temp;
    cout<<"Successfully deleted"<<endl<<endl;
    }
    else cout<<"Invalid index "<<endl<<endl;

}

void reverse(struct Node *h)
{
    struct Node *p,*q,*r;

    p=h;
    q=NULL;
    r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}
int main()
{  

   while(1)
   {
        cout<<"Enter 1 to create a linkedlist "<<endl;
        cout<<"Enter 2 to to insert a element in list "<<endl;
        cout<<"Enter 3 to delete a element in list "<<endl;
        cout<<"Enter 4 to print linkedlist "<<endl;
        cout<<"Enter 5 to reverse the list "<<endl;
        cout<<"Enter 6 to search a element in list"<<endl;
        cout<<"Enter 7 to find max element in list"<<endl;
        cout<<"Enter 8 to calculate the sum of the list "<<endl;
        cout<<"Enter 9 to see the lenght of list "<<endl;
        cout<<"Enter 0 to exit "<<endl<<endl;
        char choice;
        cout<<"Enter Your choice :";
        cin>>choice;

        if(choice=='1')
        {
            if(head==NULL){
            cout<<"Enter the Number of element you want to add :";
            int n;
            cin>>n;
            cout<<"Enter "<<n<<"  Elements ";
            int arr[n];
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }

            create(arr,n);
            }
            else 
            {
                cout<<"List has already created "<<endl<<endl;
            }
        }
       else if(choice=='2')
        {
            int ele,ind;
            cout<<"Enter the index and value :";
            cin>>ind>>ele;
            insert(head,ind,ele);
        }
        else if(choice=='3')
        {
            int ind;
            cout<<"Enter the index you want to delete :";
            cin>>ind;
            delet_index(head,ind);
        }

        else if(choice=='4')
        {
            cout<<"list :";
            print(head);
            cout<<endl<<endl;
        }
        else if(choice=='5')
        {
            reverse(head);
            cout<<"list reversed successful"<<endl<<endl;
        }
        else if(choice=='6')
        {
            int ele;
            cout<<"Enter the number you want to search :";
            cin>>ele;
            string s=search(head,ele);
            cout<<s<<endl<<endl;
        }
        else if(choice=='7')
        {
            cout<<"Max element is :"<<maxele(head)<<endl<<endl;
        }
        else if(choice=='8')
        {
            cout<<"Sum of all element is :"<<sum(head)<<endl<<endl;
        }

        else if(choice=='9')
        {
            cout<<"The lenght of the list is :"<<count(head)<<endl<<endl;
        }
        else if(choice=='0')
        {
            break;
        }
        else cout<<"WRONG INPUT "<<endl<<endl; 

   }
    cout<<"_________Created by Shahriar Mahmud Arman_____________"<<endl;
    cout<<"          Email : iamarman252575@gmail.com    "<<endl;

}
