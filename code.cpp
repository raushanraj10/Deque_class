#include<iostream>
using namespace std;
struct Node
{
public:
    Node *prev;
    Node *next;
    int val;
};
class Deque
{
private:
    Node *start;
public:
    Deque()
    {
        start=NULL;
    }
    void insertfront(int data);
    void insertrear(int data);
    void display();
    void deletefront();
    void deleterear();
    int getfront();
    int getrear();
    ~Deque();

};
void Deque::insertfront(int data)
{
    Node *n;
    n=new Node;
    n->val=data;
    if(start==NULL)
    {
       n->prev=n;
       n->next=n;
       start=n;
    }
    else
    {
        n->next=start;
        n->prev=start->prev;
        Node *t;
        t=start->prev;
        t->next=n;
        start->prev=n;
        start=n;
    }
}
void Deque::insertrear(int data)
{
    Node *n;
    n=new Node;
    n->val=data;
    if(start==NULL)
    {
      start=n;
      n->prev=n;
      n->next=n;
    }
    else
    {
        Node *t;
        t=start->prev;
        n->next=t->next;
        n->prev=t;
        t->next=n;
        start->prev=n;
    }
}
void Deque::display()
{
    if(start==NULL)
        cout<<" no data ";
    else{
            Node *t;
            t=start;
        while(start!=t->next)
            {cout<<" "<<t->val;
            t=t->next;}
           cout<<" "<<t->val<<endl;
        }
}
void Deque::deletefront()
{
    if(start==NULL)
        cout<<" no data left to delete ";
         else{
            Node *t,*r;
           t=start->next;
           r=start->prev;
           if(start->next==t->next)
           {
               delete start;
               start=NULL;
           }
           else
           {
                t->prev=start->prev;
                r->next=t;
                delete start;
                start=t;
           }
         }
}
void Deque::deleterear()
{
    if(start==NULL)
        cout<<" nothing to delete ";
    else
    {
        Node *t;
        t=start->next;
        if(start->next==t->next)
        {
            delete start;
            start=NULL;
        }
        else
        {
            t=start->prev;
            start->prev=start->prev->prev;
            start->prev->next=start;
            delete t;
        }
    }
}
int Deque::getfront()
{
    try{
       if(start==NULL)
        throw 0;
       else
        return start->val;
       }
       catch(int e){
       cout<<" no data available ";}
}
int Deque::getrear()
{
    try{
    if(start==NULL)
        throw 0;
    else
      return start->prev->val;
    }
    catch(int e)
    {
        cout<<" no data available ";
    }
}
Deque::~Deque()
{
    if(start!=NULL)
    {
        Node *t,*r;
        t=start;
        r=start;
        if(start==t->next)
            delete start;
        else
            {
        while(t->next!=start)
        {
            r=t;
            t=t->next;
            delete r;
        }
        delete t;
           }
     }
}
