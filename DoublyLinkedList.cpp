#include<conio.h>
#include<iostream>
#include<stdio.h>
class DLL
{
private:
    struct node
    {
        node *prev;
        int item;
        node *next;

    };
    node *start;
    void insertAtFirst(int data)
    {
        node *n=new node;
        n->next=start;
        n->item=data;
        n->prev=NULL;
        if(start!=NULL)
            start->prev=n;
        start=n;
    }
    void insertAtLast(int data)
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
    deleteFirst()
    {
        if(start==NULL)
            cout<<"underflow";
        node *t;
        else
        {
            t=start;
            start=t->next;
            if(t->next!=NULL)
                t->prev=NULL;
            delete t;
        }
    }
    deleteLast()
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
    node* search(int data)
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
    void insertAfter(int element,int data)
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
    deleteNode(int data)
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
};

