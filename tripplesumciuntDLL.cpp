#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
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
int count(struct node*head,int x)
{
    struct node* p1,*p2,*p3;
    int c=0;
    for(p1=head;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            for(p3=p2->next;p3!=NULL;p3=p3->next)
            {
                if((p1->data+p2->data+p3->data)==x)
                c++;
            }
        }
    }
    return c;
}
int main()
{
    struct node*head=NULL;
    insert(&head,9);
    insert(&head,8);
    insert(&head,6);
    insert(&head,5);
    insert(&head,4);
    insert(&head,2);
    insert(&head,1);

    int x=17;
    int c=count(head,x);
    cout<<c;
}
