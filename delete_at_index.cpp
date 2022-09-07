#include<iostream>
using namespace std;
struct node 
{
    int data;
    node * next;
}*first=NULL,*last=NULL;

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

int deleteNode(node *firstNode, int index)
{
    node *trailingPointer=NULL;
    int i,deletedElement=-1;
    if(index<1||index>countNode(first)) // validation of the index
        return -1;
    
    if(index==1) // if element to be delete is present at 1st position
    {   trailingPointer=first;
        deletedElement=first->data;
        first=first->next;
        delete trailingPointer;
        return deletedElement;
    }
    else // reset all other cases
    {

        for(i=0;i<index-1;i++)
        {
            trailingPointer=firstNode;
            firstNode=firstNode->next;
        }
         trailingPointer->next= firstNode->next;
         deletedElement=firstNode->data;
         delete firstNode;
         return deletedElement;
        
    }
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
    int ar[]={1,2,3,4,5,6}; 
    //int size_of_ar=sizeof(ar)/sizeof(int);
    create(ar,6);
    // linked list have indexes starting from 1
   cout<<" the deleted element is "<<deleteNode(first,1)<<endl; 
   display(first);
    return 0;
}
