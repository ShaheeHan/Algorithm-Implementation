#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

};
Node *head = NULL;

void print()
{
    Node *temp = head;
    while(temp->next!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
    puts("");
}


void rev()
{
    struct Node *curr,*prev,*next;
    curr = head;
    prev = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

}

void Inh(int x)
{
    Node *temp = new Node();
    temp->data = x;
    if(head==NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }
    Node *temp1 = head;
    temp->next = temp1;
    temp1->prev = temp;
    temp->prev = NULL;
    head = temp;

}

void In(int x)
{
    Node *temp = new Node();
    temp->data = x;
    if(head==NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }
    Node *temp1 = head;
    while(temp1->next!=NULL)
        temp1 = temp1->next;
    //temp1 = temp1->prev;


     temp->prev = temp1;
     temp->next = NULL;
     temp1->next = temp;
}

void rPrint()
{
    Node *temp = head;
    if(temp==NULL)
        return;
    while(temp->next!=NULL)
        temp=temp->next;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    puts("");
}

int main()
{

/*
    Insert(1);
    print();
    Insert(12);print();
    Insert(-1);print();
    Insert(9);print();
    Insert(0);print();
    Insert(122);print();
    print();
    printf("--------------------------------------\n");
    Inn(11111,2);
    print();
    Inn(23232323,3);
    print();
    Inn(0,1);
    print();
    rev();
    print();
*/
    In(1);
    print();
    In(12);print();
    In(-1);print();
    In(9);print();
    In(0);print();
    In(122);print();
    print();
    printf("--------------------------------------\n");

   return 0;
}
