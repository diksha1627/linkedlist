#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   struct node*next;
}*start=NULL;
void create();
void reverse(struct node*);
void display();
int main()
{
    create();
    reverse(start);
    //display();
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
void reverse(struct node*start)
{
   if(start==NULL)
   return;
   else
   {
       reverse(start->next);
       printf("%d ",start->data);
   }
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

