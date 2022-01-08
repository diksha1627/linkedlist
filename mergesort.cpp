#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node*next;
};
void printList(struct Node*head)
{
    struct Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
void push(struct Node**head,int v)
{
    struct Node*temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=v;
    temp->next=*head;
    *head=temp;
}
struct Node*merge(struct Node*first,struct Node*second)
{
    if(first==NULL)
    return second;
    if(second==NULL)
    return first;
    struct Node*result=NULL;
    if(first->data<=second->data)
    {
        result=first;
        result->next=merge(first->next,second);
    }
    else
    {
        result=second;
        result->next=merge(first,second->next);
    }
    return result;
}
void frontsplit(struct Node*head,struct Node**first,struct Node**second)
{
    struct Node*slow=head;
    struct Node*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    *first=head;
    *second=slow->next;
    slow->next=NULL;
}

void mergesort(struct Node**head)
{
    struct Node*a;
    struct Node*b;
    frontsplit(*head,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *head=merge(a,b);
}
int main()
{
    int n,num;
    cout<<"Enter the no. of elements in list : ";
    cin>>n;
    struct Node*head=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        push(&head,num);
    }
    //mergesort(&head);
    printList(head);
    return 0;
}