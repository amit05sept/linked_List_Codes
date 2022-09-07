#include<iostream>
using namespace std;

struct node 
{
    int data;
    node * next;
}*first=NULL,*first2=NULL,*last=NULL,*last2=NULL;




// this create is modified for merging two linked list.
node * create(int ar[],int n)
{
    node *temp,*ft,*lt;
    temp=new node;
    temp->data=ar[0];
    temp->next=NULL;
    ft=temp;
    lt =temp;
    for(int i=1;i<n;i++)
    {
        temp= new node;
        temp->data=ar[i];
        temp->next=NULL;
        lt->next=temp;
        lt=temp;
    }
    return ft;
    
}




node* mergeList(node *f,node *s)
{
    node *t,*l;
    if(f->data<s->data)
    {
        t=l=f;
        f=f->next;
        l->next=NULL;
    }
    else
    {
        t=l=s;
        s=s->next;
        l->next=NULL;
    }
    while(f&&s)
    {
        if(f->data<s->data)
        {
            l->next=f;
            l=f;
            f=f->next;
            l->next=NULL;
        }
        else
        {
            l->next=s;
            l=s;
            s=s->next;
            l->next=NULL;
        }
    }
    if(f)
    {
        l->next=f;
        f=NULL;
    }
    if(s)
    {
        l->next=s;
        s=NULL;
    }
  return t;
}

void display(node *firstNode)
{
    if(firstNode==NULL)
    {
        cout<<"\n!!! EMPTY !!!! \n";
    }
    else
    {
        while(firstNode)
        {
           cout<<" "<<firstNode->data<<" ";
           firstNode=firstNode->next;
         }
    }
}
int main()
{
    int ar[]={2,9,10,15};
    int ar2[]={4,6,13};
    int n1=4,n2=3;
    first=create(ar,n1);
    first2=create(ar2,n2);
    display(first);
    cout<<"\n\n";
    display(first2);
    cout<<"\n\n";
    node *third=mergeList(first,first2);
    display(third);
    return 0;
}