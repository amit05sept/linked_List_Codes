#include<iostream>
using namespace std;
struct node{
    int data;
    node * next;

}*first=NULL,*last=NULL;

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
//insert function for linked list.
void insertAtAnyPosition(int key,int pos)
{
    node *temp=new node;
    temp->data=key;
    temp->next=NULL;

    if((pos<0||pos>countNode(first))&&(pos!=0))
    {
        // if(pos==0)  // this is when pos!=0 is not added.
        // {

        // }
        //else
        //{
            cout<<"\n!!!! INVALID \n"<<endl;
            return;
       // }
    }
     if(countNode(first)==0)  // if temp is first element in the list.
     {
        first=temp;
        last=temp;
     }
     else   // if temp is not the first element.
     {   
        if(pos==0) // if temp is to be added at position 0 or at first.
        {
            temp->next=first;
            first=temp;
        }
        else if (pos==countNode(first)) // if temp is to be added at last.
        {
            last->next=temp;
            last=temp;
        }
        else // reset at any other position
        {   
            node *Pointer=first;
            for(int i=0;i<pos;i++)
            Pointer=Pointer->next;
            temp->next=Pointer->next;
            Pointer->next=temp;
        }
     }
}

void insertInSortedList(node * firstNode, int key)
{
    node *trailingPointer =NULL,*headPointer =firstNode;
    node * temp= new node;
    int i;
    temp->data=key;
    temp->next=NULL;
    if(countNode(firstNode)==0)
    {
        first=temp;
        last=temp;
    }
    else if(firstNode->data>key)
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
        temp->next=trailingPointer->next;
        trailingPointer->next=temp;
        trailingPointer=temp;
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
    insertAtAnyPosition(2,0);
    insertAtAnyPosition(5,1);
    insertAtAnyPosition(6,2);
    insertAtAnyPosition(7,3);
    insertAtAnyPosition(10,4);
    cout<<endl<<countNode(first)<<endl;
    display(first);
    insertInSortedList(first,11);
    cout<<"\n";
    display(first);



    return 0;
}