#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    struct node*next;
    struct node*prev;
};
void insert(struct node**head,char v)
{
    struct node*temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=v;
    temp->next=NULL;
    temp->prev=NULL;
    if(*(head)==NULL)
    {
        *head=temp;
    }
    else
    {
        q=*head;
        while(q->next!=NULL)
        q=q->next;
       temp->next=q->next;
       temp->prev=q;
       q->next=temp;
    }
}
void rotate(struct node* &head, int pos)
{
    // return without any changes if position is 0.
    if(pos==0) return;
 
    // Finding last node.
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    // making the list circular.
    temp->next=head;
    head->prev=temp;
 
    // move head and temp by the given position.
    int count=1;
    while(count<=pos)
    {
        head=head->next;
        temp=temp->next;
        count++;
    }
 
    // now again make list un-circular.
    temp->next=NULL;
    head->prev=NULL;
}
void display(struct node*head)
{
    struct node*q=head;
    while(q!=NULL)
    {
        cout<<q->data<<" ";
        q=q->next;
    }
}
int main()
{
    struct node*head=NULL;
    insert(&head,'a');
    insert(&head,'b');
    insert(&head,'c');
    insert(&head,'d');
    insert(&head,'e');

    int x=2;
   rotate(head,x);
   display(head);
}
