#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*head=NULL,*tail=NULL;

void create(int arr[],int n)
{
    if(head==NULL){
    struct Node *temp,*last;
    head=new Node;
    head->data=arr[0];
    head->next=NULL;
    head->prev=NULL;
    last=head;
    tail=last;

    for(int i=1;i<n;i++)
    {   
        temp=new Node;
        temp->data=arr[i];
        temp->next=NULL;
        temp->prev=last;
        last->next=temp;
        last=temp;
        tail=last;
    }
    }
    else cout<<"List already created "<<endl<<endl;

}

void print(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

int count(struct Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    int i=0;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}

void insert(struct Node *p,int index ,int key)
{
    if(index>count(head)+1)
    {
        cout<<"WRONG INDEX"<<endl<<endl;
        return;
    }
    if(index==1)
    {
        struct Node *temp;
        temp=new Node;
        temp->data=key;
        temp->prev=NULL;
        temp->next=head;
        head->prev=temp;
        head=temp;
        cout<<"Inserted successfully"<<endl<<endl;
    }
    else if(count(head)+1==index)
    {
        struct Node *temp;
        temp = new Node ;
        temp->data=key;
        temp->prev=tail;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
        cout<<"Inserted successfully"<<endl<<endl;
    }
    else if(count(head)<=index){
    {
        int k=index-2;
        struct Node *temp,*x,*y;
        x=p;
        while(k--)
        {
            x=x->next;
        }
        y=x->next;
        temp=new Node;

        temp->data=key;
        temp->prev=x;
        temp->next=y;
        x->next=temp;
        y->prev=temp;
    }
    cout<<"Inserted successfully"<<endl<<endl;
    }
}

void delet(struct Node *p,int index)
{
    if(index>count(head))
    {
        cout<<"WRONG INDEX"<<endl<<endl;
        return;
    }
    if(index==1)
    {
        if(head->next==NULL)
        {
            head=NULL;
            return;
        }
        struct Node *temp=head;
        if(head->next!=NULL) head=head->next;
        head->prev=NULL;
        delete temp;
        cout<<"Deleted successfully"<<endl<<endl;
        return;
        

    }
    else if(count(head)==index)
    {
        tail=tail->prev;
        struct Node *temp;
        temp=tail;
        tail->next=NULL;
        cout<<"Deleted successfully"<<endl<<endl;
        return;

    }
    else {
    int k=index-1;
    struct Node *temp,*x,*y;
    x=p;
    while(k--)
    {
        x=x->next;
    }
    temp=x->prev;
    y=x->next;
    
    temp->next=y;
    y->prev=temp;

    delete x;
    cout<<"Deleted successfully"<<endl<<endl;
    }
}

void reverse(struct Node *h)
{
    struct Node *p,*temp,*r;
    p=h;
    tail=p;
    while(p)
    {  
        temp=p->next;
        p->next=p->prev;

        p->prev=temp;

        p=p->prev;

        if(p!=NULL and p->next==NULL)
        {
            head=p;
        }

    }
    
}

long long sum(struct Node *p)
{
    long long x=0;
    while(p!=NULL)
    {
        x+=p->data;
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
            cout<<"Enter "<<n<<"  Elements :";
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
            delet(head,ind);
        }

        else if(choice=='4')
        {
            if(count(head)==0)
            {
                cout<<"List is empty "<<endl<<endl;
            }
            else{
            cout<<"list :";
            print(head);
            cout<<endl<<endl;
            }
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
    cout<<"_________Crated by Shahriar Mahmud Arman_____________"<<endl;
    cout<<"          Email : iamarman252575@gmail.com    "<<endl;

}