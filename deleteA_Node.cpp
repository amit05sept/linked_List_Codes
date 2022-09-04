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

int deleteNode(node *firstNode, int key)
{
    node *trailingPointer=NULL,*headPointer=firstNode;
    node *temp=NULL;
    int i,deletedElement=-1;
    if(countNode(firstNode)==0)   // if no element is present 
    {
        return -1;
    }
    else if(headPointer->data==key) // if element to be delete is present at 1st position
    {
        temp=headPointer;
        first=first->next;
    }
    else // reset all other cases
    {

        for(i=1;(headPointer->data!=key)&&(headPointer);i++)
        {
            trailingPointer=headPointer;
            headPointer=headPointer->next;
        }
        if(headPointer==NULL) // if element is not present 
        {
            return -1;
        }
        else if(headPointer==last) // element to be deleted is present at the last.
        {
            temp=trailingPointer->next;
            trailingPointer->next=NULL;
            last=trailingPointer;
        }
        else  // reset all cases.
        {
            temp=headPointer;
            trailingPointer->next= headPointer->next;
            temp->next=NULL;
        }
        
    }
    deletedElement=temp->data;
    delete temp;
    return deletedElement;
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
    
   cout<<" the deleted element is "<<deleteNode(first,6)<<endl;
   display(first);
    return 0;
}
