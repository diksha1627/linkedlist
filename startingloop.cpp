// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

// Function to detect and remove loop
// in a linked list that may contain loop
Node* detectAndRemoveLoop(Node* head)
{
	 if(!head)
    return NULL;
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
		cout << "Loop starting node is " << res->key;

	return 0;
}
