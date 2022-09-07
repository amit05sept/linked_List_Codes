#include<iostream>
using namespace std;
struct node 
{
    int data;
    node * next;
}*first=NULL,*first2=NULL,*last=NULL,*last2=NULL;

void create(int ar[],int n)
{
    node *temp;
    temp=new node;
    temp->data=ar[0];
    temp->next=NULL;
    first=temp;
    last =temp;
    for(int i=1;i<n;i++)
    {
        temp= new node;
        temp->data=ar[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
    
}


int countNode(node *firstNode)
{
    int Length=0;
    while(firstNode)
    {
        Length++;
        firstNode=firstNode->next;
    }
    return Length;
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
void reverseList_array(node *firstNode)
{
    int n=countNode(first);
    int a[n];
    node *temp=firstNode;
    for(int i=0;i<n;i++)
    {
        a[i]=firstNode->data;
        firstNode=firstNode->next;
    }
    for(int i=n-1;i>=0;i--)
    {
        temp->data=a[i];
        temp=temp->next;
    }
}
void reverseList( node *p)
{
    node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;

}
void ReverseList_recursively(node *q,node *p)
{
    if(p==NULL)
    first=q;
    else
    {
        node *temp=p->next;
        p->next=q;
        q=p;
        p=temp;
        ReverseList_recursively(q,p);
    }
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
        l=f;
        f=NULL;
    }
    if(s)
    {
        l=s;
        s=NULL;
    }
  return t;
}
int main()
{
   int ar[]={1,2,3,4,5,6}; 
   create(ar,6);
   display(first);
   cout<<"\n\n\n";
    // cout<<"\nafter reversing the links we get (sliding window) \n";
//    reverseList(first);
//    display(first);
//    cout<<"\n\n this is with data reverse (do not use this)\n";
//    reverseList_array(first);
//    display(first);
   cout<<"\n\n this is with recursive call \n";
   ReverseList_recursively(NULL,first);
   display(first);
    return 0;
}