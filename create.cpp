#include<iostream>
using namespace std;
struct node
{
   int data;
   node * next;
}*first=NULL,*last=NULL;

void create(int a[],int n)
{
    node *temp;
    temp=new node;
    temp->data=a[0];
    temp->next=NULL;
    first=temp;
    last=first;
    for(int i=1;i<n;i++)
    {   temp=new node;
        temp->data=a[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }

}
void rdisplay(node *p)
{
    if(p==NULL)
    return;
    cout<<p->data<<" ";
    p=p->next;
    rdisplay(p);

}
void display(node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

}
int rsum(node *temp)
{
    if(temp==NULL)
    return 0;
    else 
    return rsum(temp->next) + temp->data;
}
int sum(node *temp)
{   int s=0;
    while(temp)
    {
        s+=temp->data;
        temp=temp->next;
    }
    return s;
}
int rmax(node *temp,int max)
{
    if(temp==NULL)
    return max;
    else{
        if(temp->data>max)
        max=temp->data;
        return rmax(temp->next,max);
    }

}

int rrmax(node* temp)
{
    int x=0;
    if(temp==NULL)
    return INT32_MIN;
    
    else
    {
        x=rrmax(temp->next);
        if(x>temp->data)
        return x;
        else 
        return temp->data;
    }
    
}
node * rsearch(node *temp,int key)
{
    if(temp==NULL)
    return temp;
    else{
        if(key==temp->data)
        return temp;
        else
        return rsearch(temp->next,key);
    }
}
node * fnd(node* temp,int key)
{   int count=0;
    node *q=NULL;
    while(temp!=NULL)
    {   count++;
        if(key==temp->data)
        {
            
            q->next=temp->next;
            temp->next=first;
            first=temp;
            cout<<"\nfind in  "<<count<<"  number of counts   ";
            return temp;
        }
        else
        {
            q=temp;
            temp=temp->next;
        }
    }
}
void insert(int key,int  pos)
{   
    node *temp= new node;
    temp->data=key;
    temp->next=NULL;
    
    if(pos==0)
    {
       temp->next=first;
       first=temp;
    }
    else if(pos>0)
    {
        node* p;
        p=first;
        for(int i=1;i<pos&&p;i++)
        {
            p=p->next;
        }
        if(p)
        {
          temp->next=p->next;
          p->next=temp;
        }
    }
 return;
}
 
void inst(int key)
{
    if(first==NULL)
    {
        node *temp =new node;
        temp->data=key;
        temp->next=NULL;
        first = temp;
    }
}
int main()
{
     
    /*    
          cout<<"\n the sum is "<<rsum(first);//<<sum(first);
          cout<<"\nthe maximum element is  "<<rrmax(first);//rmax(first,-122);
          cout<<"\n the key = 7 is present at address  "<<rsearch(first,7);
          cout<<" \n the key = 10 is present at address  "<<fnd(first,10)<<endl;   
    
    */
     cout<<"\n";
    insert(11,0);
    insert(19,1);
    display(first);
    node *q=rsearch(first,11);
    return 0;
}


