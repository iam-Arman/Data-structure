#include<bits/stdc++.h>
using namespace std;
class aray
{
private:

    int *A;
    int size;
    int lenght;

public:

    aray(int x)
    {
        A=new int[x];
        size=x;
        lenght=0;
    }
    void display();
    void insert(int index,int value);
    void append(int value);
    void delet(int index);
    int find(int value);
    void max_ele();
    void min_ele();
    void sort();
    int get_lenght();
    int get_size();
    


};
void aray::display()
{
    cout<<"array : ";
    for(int i=0;i<lenght;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void aray::append(int value)
{
    if(lenght>=size-1 or value>size)
    {
        cout<<"array size is maxed out"<<endl;
        return;
    }
    cout<<"Enter  "<<value<<"  Elements"<<endl;
    for(int i=0;i<value;i++)
    {
        cin>>A[lenght];
        lenght++;
    }
    
    
}

void aray::insert(int index,int value)
{
     if(lenght>=size)
     {
            cout<<"array size is maxed out"<<endl;
            return;
     }
     if(index<=0 or index>lenght)
     {
         cout<<"Invalid index"<<endl;
         return;
     }
     lenght++;
     for(int i=lenght;i>=index;i--)
     {
       A[i]=A[i-1];
     }
        A[index-1]=value;
        
}

void aray::delet(int index)
{
    if(index<=0 or index>lenght)
    {
        cout<<"Invalid index"<<endl;
        return;
    }
    for(int i=index-1;i<lenght;i++)
    {
       A[i]=A[i+1];
    }
    lenght--;
}

int aray::find(int value)
{
    if(lenght==0)
    {
        cout<<"array is empty "<<endl;
        return 0;
    }
    for(int i=0;i<lenght;i++)
    {
        if(A[i]==value)
        {
            return 1;
        }
    }
    return 0;
}

void aray::max_ele()
{
    int max=INT_MIN;
    if(lenght==0)
    {
        cout<<"array is empty "<<endl;
        return;
    }
    for(int i=0;i<lenght;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        }
    }
   cout<<"maximum element is :"<<max<<endl;
}

void aray::min_ele()
{
    int min=INT_MAX;
      if(lenght==0)
    {
        cout<<"array is empty "<<endl;
        return;
    }
    for(int i=0;i<lenght;i++)
    {
        if(A[i]<min)
        {
            min=A[i];
        }
    }
    cout<<"Minimum element is :"<<min<<endl;
}

void aray::sort()
{
    for(int i=0;i<lenght;i++)
    {
        for(int j=0;j<lenght-i-1;j++)
        {
            if(A[j]>A[j+1]) swap(A[j],A[j+1]);
        }
    }
    cout<<"array sorted successfully"<<endl;
}

int aray::get_lenght()
{
    return lenght;
}

int aray::get_size()
{
    return size;
}

int main()
{
    cout<<endl;
    cout<<"\t\t\t Enter the size of array you want to create"<<endl;
    int n;
    cin>>n;
    aray a(n);
    

    while(1)
    {
        int option;
         cout<<"\t\t\t ________________MENU_________________"<<endl<<endl;

        cout<<"\t\t\t Press 1 to append element in array   :"<<endl;

        cout<<"\t\t\t Press 2 to insert element in array   :"<<endl;

        cout<<"\t\t\t Press 3 to delete element in array   :"<<endl;

        cout<<"\t\t\t Press 4 to find element in array   :"<<endl;

        cout<<"\t\t\t Press 5 to find max element in array   :"<<endl;

        cout<<"\t\t\t Press 6 to find min element in array   :"<<endl;

        cout<<"\t\t\t Press 7 to display element in array   :"<<endl;

        cout<<"\t\t\t Press 8 to sort the array : "<<endl;

        cout<<"\t\t\t Press 9 to get lenght   :"<<endl;

        cout<<"\t\t\t Press 10 to get size "<<endl;

        cout<<"\t\t\t Press 0 to exit "<<endl;

        cin>>option;

        if(option==1)
        {
           cout<<"Enter the element you want to append : ";

            int ele;
            cin>>ele;

            a.append(ele);
        }

        else if(option==2)
        {
            cout<<"Enter the index where you want to insert element  and the value: ";

            int index,value;
            cin>>index>>value;
            a.insert(index,value);
        }
        else if(option==3)
        {
            cout<<"Enter the index where you want to delete element : ";

            int index;
            cin>>index;
            a.delet(index);
        }
        else if(option==4)
        {
            cout<<"Enter the element you want to find : ";
            int x;
            cin>>x;
            int y=a.find(x);
            if(y==1)
            {
                cout<<"Element found"<<endl;
            }
            else
            {
                cout<<"Element not found"<<endl;
            }
        }
        else if(option ==5)
        {
            a.max_ele();
        }
        else if(option==6)
        {
           a.min_ele();
           
        }

        else if(option==7)
        {
            a.display();
        }

        else if(option==8)
        {
           a.sort();
        }
        else if(option==9)
        {
            int len=a.get_lenght();
            cout<<"current lenght is: "<<len<<endl;
        }
        else if(option==10)
        {
            int sz=a.get_size();
            cout<<"The size of the array is : "<<sz<<endl;
        }

        else if(option ==0)
        {
            break;
        }
        else 
        {
            cout<<"Invalid option"<<endl;
        }

    }

    cout<<"_________Developed by Shahriar Mahmud Arman_____________"<<endl;
    cout<<"          Email : iamarman252575@gmail.com    "<<endl;
   

}