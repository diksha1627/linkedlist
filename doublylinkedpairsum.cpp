#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};

void findpair(struct node*head,int x)
{
    struct node*first;
    struct node*second;
    first=head;
    second=head;
    while(second->next!=NULL)
    second=second->next;
    bool f=false;
    while(first!=second && second->next!=first)
    {
       if((first->data+second->data)==x)
       {
           f=true;
           cout<<"("<<first->data<<","<<second->data<<")"<<endl;
           first=first->next;
           second=second->prev;
       }
       else
       {
           if((first->data+second->data)>x)
           second=second->prev;
           else
           first=first->next;
       }
    }
    if(f==false)
    cout<<"sum not found.";
}
void insert(struct node**head,int v)
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
int main()
{
    struct node*head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);
    insert(&head,8);
    insert(&head,9);

    int x=7;
    findpair(head,x);
}
