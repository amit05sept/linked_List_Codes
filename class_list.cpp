#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * next;
};
class linkedList
{
    private :
        node *first;
    public :
        linkedList(){first=NULL;}
        linkedList(int ar[],int n);
        ~linkedList();

        void display();
        void insert(int index,int x);
        int Delete(int index);
        int legnth();
};
