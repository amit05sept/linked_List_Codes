#include<iostream>
using namespace std;
struct node
{
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
// bool isLoop(node *f)
// {
//     node *q=first;
//     while(q&&f)
//     {
//         f=f->next;
//         q=(q->next)->next;
//         if(f==q)
//         return true;
//     }
//     return false;
// }

bool isLoop(node *f)
{
    node *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p&&q&&p!=q);
    if(p==q)
    return 1;
    else
    return 0;
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
node* removeElements(node* head, int val) {
      if(!head){return NULL;}
        node *back=NULL,*check=head;
        while(check)
        {
            if(check->data==val)
            {   
                if(check==head)
                {    
                  head=head->next;
                  back=head;
                  check=head;
                }
                else
                {
                    back->next=check->next;
                    check=check->next;
                }
            }
            else
            {
                back=check;
                check=check->next;
            }
        }
        return head;
        
    }

int main()
{
    int ar[]={2,1,5,1,1,5,1,10};
    create(ar,8);
    // last->next=(first->next)->next;
    // cout<<" \n is a loop : (0 for no, 1 for yes )  :  "<<isLoop(first);
    node * newHead= removeElements(first,1);
    display(newHead);
    return 0;
}