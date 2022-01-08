#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*next;
}*start=NULL;
void create();
void move();
void display();
int main()
{
  create();
  move();
  display();
  return 0;
}
void create()
{
    struct node*temp,*q;
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
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
void move()
{
    struct node*temp,*q;
    temp=start;
    q=start;
    while(q->next!=NULL){
        temp=q;
     q=q->next;
    }
    
    //while(temp->next!=q)
    //temp=temp->next;
    q->next=start;
    temp->next=NULL;
    start=q;
}
void display()
{
    struct node*q;
    q=start;
    while(q!=NULL)
    {
       printf("%d ",q->data);
       q=q->next;
    }
}