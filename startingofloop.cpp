#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node*next;
};
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node* head)
{
    if(!head)
    return;
    Node*low=head;
    Node*high=head;
    while(high!=NULL && high->next!=NULL)
    {
       low=low->next;
       high=high->next->next;
       if(low==high)
       break;
    }
    if(low==head)
    {
       return low;
    }
    else if(low==high)
    {
        low=head;
        while(high->next!=low->next)
        {
            high=high->next;
            low=low->next;
        }
    }
    return low;
}
 
/* Driver program to test above function*/
int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* res = detectAndRemoveLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->data;
 
    return 0;
}