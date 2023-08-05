#include <conio.h>
#include<iostream>
using namespace std;
class DLL{
private:
    struct node
    {
        node *prev;
        int item;
        node *next;

    };
    node *start;
public:
    DLL() : start(nullptr) {}

    void insertAtFirst(int data);
    void insertAtLast(int data);
    void deleteFirst();
    void deleteLast();
    node* search(int data);
    void insertAfter(int element, int data);
    void deleteNode(int data);
    void display();
};

void DLL:: insertAtFirst(int data)
    {
        node *n=new node;
        n->next=start;
        n->item=data;
        n->prev=NULL;
        if(start!=NULL)
            start->prev=n;
        start=n;
    }
    void DLL::insertAtLast(int data)
    {
        node *n,*t;
        n=new node;
        n->next=NULL;
        n->item=data;
        if(start==NULL)
        {
            n->prev=NULL;
            n->next=start;
            start=n;
        }
        else
        {
            t=start;
            while(t->next!=NULL)
                t=t->next;
            n->prev=t;
            t->next=n;
        }
    }
    void DLL::deleteFirst()
    {
        if(start==NULL)
            cout<<"underflow";

        else
        {
            node *t;
            t=start;
            start=t->next;
            if(t->next!=NULL)
                t->prev=NULL;
            delete t;
        }
    }
    void DLL::deleteLast()
    {
        if(start==NULL)
            cout<<"Underflow";
        else
        {
            node *t=start;
            if(t->next!=NULL)
            {
                while(t->next!=NULL)
                    t=t->next;
                node *t2=t->prev;
                t2->next=NULL;
                delete t;
            }
            start=NULL;
            delete t;
        }
    }
    DLL::node* DLL::search(int data)
    {
        if(start==NULL)
            cout<<"Underflow";
        node *t=start;
        while(t!=NULL)
        {
            if(t->item==data)
                return t;
            t=t->next;

        }
        return NULL;
    }
    void DLL::insertAfter(int element,int data)
    {
        node *temp=search(element);
        if(temp!=NULL)
        {
            node *n=new node;
            n->prev=temp;
            n->item=data;
            n->next=temp->next;
            temp->next=n;
        }
        else
            cout<<"element search flaild ";

    }
    void DLL::deleteNode(int data)
    {
        node *t=search(data);
        if(t!=NULL)
        {
            node *t2=t->prev;
            if(t->next!=NULL)
                t2->next=t->next;
            t2->next=NULL;
            delete t;

        }
        else
            cout<<"element Search failed";
    }
    void DLL::display() {
    node *current = start;
    while (current != nullptr) {
        cout << current->item << " ";
        current = current->next;
    }
    cout << endl;
   }

int main() {
    DLL myList;

    myList.insertAtFirst(10);
    myList.insertAtLast(20);
    myList.insertAtLast(30);
    myList.insertAfter(20, 25);

    myList.display();
    myList.deleteFirst();
    myList.deleteNode(30);
    myList.deleteLast();

    getch();



    return 0;
}
