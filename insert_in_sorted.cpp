#include<iostream>
using namespace std;
struct node{
    int data;
    node * next;
}*first=NULL,*last=NULL;


void create(int ar[],int Length)
{   
    int i;
    node *firstNode=new node;
    firstNode->data=ar[0];
    firstNode->next=NULL;
    first=firstNode;
    last=firstNode;
    for(i=1;i<Length;i++)
    {
        node *temp=new node;
        temp->data=ar[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
    
}

void display(node *firstNode)
{
    while(firstNode)
    {
        cout<<" "<<firstNode->data;
        firstNode=firstNode->next;
    }
    cout<<endl;
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
void insertInSortedlist(node *firstNode,int key)
{   
    node *temp=new node;
    node *trailingPointer=NULL, *headPointer=firstNode;
    int i;
    temp->data=key;
    temp->next=NULL;
    if(countNode(firstNode)==0)
    {
      first=temp;
      last=temp;
    }
    else
    {   
        if(firstNode->data>key)
        {
            temp->next=first;
            first=temp;
        }
        else if(last->data<key)
        {
            last->next=temp;
            last=temp;
        }
        else
         {
              for(i=1;(headPointer->data<key)&&(headPointer);i++)
              {
                  trailingPointer=headPointer;
                  headPointer=headPointer->next;
              }
               temp->next = trailingPointer->next;
               trailingPointer->next=temp;              
         }
    }
}
int main()
{
  int ar[]={10,20,30,40,50};
  create(ar,5);
  cout<<countNode(first)<<endl;
  display(first);

  insertInSortedlist(first,55);
  display(first);
  return 0;
}