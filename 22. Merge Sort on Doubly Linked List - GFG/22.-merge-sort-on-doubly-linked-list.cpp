// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


//Function to sort the given doubly linked list using Merge Sort.
Node* merge(Node *head1, Node *head2) {
    
    if(head1 == NULL) {
        return head2;
    }
    
    if(head2 == NULL) {
        return head1;
    }
    
    if(head1->data < head2->data) {
        Node *temp = merge(head1->next, head2);
        head1->next = temp;
        temp->prev = head1;
        return head1;
    } else {
        Node *temp = merge(head1, head2->next);
        head2->next = temp;
        temp->prev = head2;
        return head2;
    }
    
}
struct Node *sortDoubly(struct Node *head) {
    
    if (!head or !head->next) return head;
	Node* slow = head;
	Node* fast = head;
	Node* prev = NULL;
	
	while (fast and fast->next) {
	    prev = slow;
	    slow = slow->next;
	    fast = fast->next->next;
	}
	prev->next = NULL;
	slow->prev = NULL;
	
	Node* head1 = sortDoubly(head);
	Node* head2 = sortDoubly(slow);
	return merge(head1, head2);
	
}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends