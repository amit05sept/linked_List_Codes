#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
}*first,*last;
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
void rdisplay(node *temp) // recursive way of displaying the elements of the list.
{
    if(temp==NULL)
    return;
    cout<<temp->data<<" ";
    rdisplay(temp->next);
}

int rsum(node *temp) // recursive way of finding the sum of the list
{  if(temp==NULL)
{
    return 0;

}
else{
    return rsum(temp->next)+temp->data;
}
}

int rmax(node *temp)  // recursive way of finding the maximun element 
{
    if(temp==NULL)
    return INT32_MIN;
    else
    {
        int x=rmax(temp->next);
        if(x>temp->data)
        return x;
        else
        return temp->data;
    }
}

node * rsearch(node * temp,int key) // recursive way of searching the element
{   
    if(temp==NULL)
    {
        return NULL;
    }
    else{

        if(temp->data==key)
        {
            return temp;
        }
        else{
            return rsearch(temp->next,key);
        }
    }

}
node *ImproveLinearSearch(node *temp, int key) // brings the element at front.
{
      node * ElementBefore = NULL;

      while(temp!=NULL)
      {
        if(temp->data==key)
        {
            ElementBefore->next=temp->next;
            temp->next=first;
            first=temp;
             return temp;
        }
        ElementBefore=temp;
        temp=temp->next;

      }
      return NULL;
}

int findPosition(node *firstNode,node * Element) // only when element exist in the list 
{   
    int i;
    for(i=1;firstNode->data!=Element->data;i++,firstNode=firstNode->next)
    {
            // no need for any statment here this loop works fine
    }
    return i;

}


int CountNode(node *firstNode) // counts the number of nodes
{
    int length=0;
    while(firstNode)
    {
        length++;
        firstNode=firstNode->next;
    }
    return length;
}
void InsertAtPosition(int key,int pos) // any position 
{
    node *temp=new node;
    temp->data=key;
    temp->next=NULL;
    if(pos<0||pos>CountNode(first))
    {
        return;
    }
    if(pos==0)
    {
        temp->next=first;
        first=temp;
    }
    else if(pos==CountNode(first))
    {
        last->next=temp;
        last=temp;
    }
    else{
        node *Position;
        Position=first;
        for(int i=0;i<pos;i++)
        {
            Position=Position->next;
        }
        temp->next=Position->next;
        Position->next=temp;

    }
}
int main()
{   
    // int ar[]={1,2,4,5,8,23,3};
    // int size_of_ar=sizeof(ar)/sizeof(int);
    // create(ar,size_of_ar);
    InsertAtPosition(1,0);
    InsertAtPosition(2,0);
    InsertAtPosition(3,0);
    InsertAtPosition(4,0);
    InsertAtPosition(15,0);
    InsertAtPosition(6,0);
    
    // rdisplay(first);
    // int sum_of_list=rsum(first);
    // cout<<"\nsum = "<<sum_of_list<<endl;

    // // section{
    node * Element= rsearch(first,3);
    // if(Element)
    // {   int Pos=findPosition(first,Element);
    //     cout<<"\n found it at position h "<<Pos<<endl;
    // }
    // else{
    //     cout<<"\n not found it."<<endl;
    // }
    // // }section

    // cout<<"  m......................................";
    Element=NULL;
    Element=ImproveLinearSearch(first,3);
    if(Element)
    {  
        int Pos=findPosition(first,Element);
        cout<<"\n found it at position a "<<Pos<<endl;
    }
    else{
        cout<<"\n not found it."<<endl;
    }
    cout<<"  n ......................................";
    

    Element=ImproveLinearSearch(first,3);
    if(Element)
    {  
        int Pos=findPosition(first,Element);
        cout<<"\n found it at position x"<<Pos<<endl;
    }
    else{
        cout<<"\n not found it."<<endl;
    }
    rdisplay(first);
    cout<<"  x ......................................";

    return 0;
}

