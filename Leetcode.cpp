#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode * removeElement(ListNode *head, int n) // remove element from end
// {
//     int i=0;
//     ListNode *front=head,*back;
//     while(front->next)
//     {
//         if(i>=n)
//         {
//             if(back==nullptr)
//             back=head;
//             else
//             back=back->next;
//         }
//         front=front->next;
//         i++;
//     }
//     if(front->next==NULL)
//     {
//         back->next=NULL;
//         delete(front);
//     }
//     else
//     {

//     }


// }

ListNode * removeElement(ListNode *head, int n) // remove element from end
{
    ListNode *front=head,*dummy=NULL;
    int size=0;
    while(front)
    {
        size++;
        front=front->next;
    }
    front=head;
    int i=1;
    if(size-(n-1)==1)
    {
        front=head;
        head=head->next;
        front->next=NULL;
        delete(front);
        return head;
    }
    while(i<size)
    {
        if((i+1)==size-(n-1))
        {
            dummy=front->next;
            front->next=front->next->next;
            delete(dummy);
            return head;
        }
        front=front->next;
        i++;
    }

}

void Rem(ListNode *head)
{
    
}
int main()
{
    ListNode *head= new ListNode(0);
    ListNode; // check wheater by changing head it changes or not.
    cout<<head->val;
    cout<<" h\n";
    
    return 0;
}