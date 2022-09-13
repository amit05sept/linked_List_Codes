#include<iostream>
using namespace std;
 struct node{
    int data;
    node  *next;
 }*head;

 void create(int a[],int n)
 {
    node *t,*last;
    head=new node;
    head->data=a[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }



 }

 void display(node *h)
 {
    node *p=h;
    do{
        cout<<" "<<p->data;
        p=p->next;
    }while(p!=head);
    

 }

 void Rdisplay(node *h)
 {
    static int flag=0;
    if(h!=head|| flag==0)
    {
        flag=1;
        cout<<" "<<h->data;
        Rdisplay(h->next);
    }
    flag=0;
 }
int Length(node *p)
{
    int count=0;
    do
    {
        count++;
        p=p->next;
    }while(p!=head);
    return count;
}
 void insert(node *p, int index,int x)
 {
    node *t;
    int i;
    if(index<0||index>Length(p))
    {
        cout<<"\n\nnot valid index\n\n";
        return;
    }
    if(index==0)
    {
        t=new node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else{
            while(p->next!=head)
            p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else{
        for(int i=0;i<index-1;i++)
        p=p->next;
        t=new node;
        t->data=x;
        t->next=p->next;
        p->next=t;
        
    }
 }

 int main()
 {
    int A[]={1,2,3,4,5,6};
    create(A,6);
    insert(head,0,10);
    // display(head); 
    Rdisplay(head);
    return 0;
 }
