#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   struct node*next;
}*start=NULL;
void create();
struct node* reverse(struct node*);
void display();
int main()
{
    create();
    reverse();
    display();
    return 0;
}
void create()
{
    int n,m;
    printf("Enter the no. of nodes to add : ");
    scanf("%d",&n);
    struct node*temp,*q;
    for(int i=0;i<n;i++)
    {
        printf("Enter the data of the node : ");
        scanf("%d",&m);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=m;
        if(start==NULL)
        {
            temp->next=start;
            start=temp;
        }
        else
        {
            q=start;
            while(q->next!=NULL)
            q=q->next;
            temp->next=q->next;
            q->next=temp;
        }
    }
}
struct node*reverse(struct node*start)
{
    struct node*nex,*prev,*curr;
    nex=NULL;
    prev=NULL;
    curr=start;
    int k=4,c=0;
    while(curr!=NULL && c<k)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        c++;
    }
    if(nex!=NULL)
    start->next=reverse(nex);
    start=prev;
}
void display()
{
    struct node*q;
    q=start;
    while(q!=NULL)
    {
        printf("%d->",q->data);
        q=q->next;
    }
}

