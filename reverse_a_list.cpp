#include<iostream>
#include<vector>
using namespace std;
struct node 
{
    int data;
    node * next;
}*first=NULL,*first2=NULL,*last=NULL,*last2=NULL;

void create(int ar[],int n)
{   if(n==0)
    {
        first=NULL;
        return;
    }
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
// void displayAdrress(node *head)
// {
//     while(head)
// }
node* ReverseList_recursively(node *head,node *q)
{
    if(head==NULL)
    {
        head=q;
        return head;
    }
    else
    {
         node *newhead = ReverseList_recursively(head->next,head);
         head->next=q;
        // node *temp=p->next;
        // p->next=q;
        // q=p;
        // p=temp;
        // ReverseList_recursively(q,p);
        return newhead;
    }
}

bool isPalindrome(node *head)
{   
    if(!head){return false;}
    node *head2=NULL;
    node* temp=head;
    vector<int> A;
    while(temp)
    {
        A.push_back(temp->data);
        temp=temp->next;
    }
    int L=A.size();
    for(int i=L-1;i>=L/2;i--)
    {
        if(A[i]!=head->data)
        {
            return false;
        }
        head=head->next;
    }
    return true;
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
   int ar[]={}; 
   if(sizeof(ar)==0)
   {
    cout<<"\n\ncan not procceed with this input";
   }
   else
   {

     create(ar,1);
   }
   display(first);
   cout<<"\n\n\n";
    // cout<<"\nafter reversing the links we get (sliding window) \n";
//    reverseList(first);
//    display(first);
//    cout<<"\n\n this is with data reverse (do not use this)\n";
//    reverseList_array(first);
//    display(first);
//    cout<<"\n\n this is with recursive call \n";
//    node *head=ReverseList_recursively(first,NULL);
//    display(head);
    cout<<"\n\n\n";
    cout<<isPalindrome(first);
    cout<<"\n\n";

    return 0;
}