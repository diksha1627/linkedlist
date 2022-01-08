#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   struct node*next;
}*start=NULL;
void create();
void reverse();
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
void reverse()
{
    struct node*p1,*p2,*p3;
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
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

