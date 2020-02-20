/*
Write a function that moves last element to front in a given singly Linked List.
For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4

Sample Input :
 1 2 3 4 5 6 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. 
This -1 is not part of the linked list. Size of given linked list is 6.
Sample Output :
 6 1 2 3 4 5

*/
#include<iostream>
using namespace std;

 template <typename T>
 class Node {
	public:
	T data;
	Node* next;
 
	Node(T data) {
 next = NULL;
 this->data = data;
	}
 
	~Node() {
 if (next != NULL) {
 delete next;
 }
	}
 };

void add_node(Node<int>* head , int val)
{
	Node<int>*temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	Node<int>* newnode = new Node<int>(val);
	temp->next = newnode;
}
void print_list(Node<int>*head)
{
	Node<int>*temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

Node<int>* moveToFront(Node<int> *head_ref) {
	if(!head_ref->next)
		return head_ref;
	else if(!head_ref->next->next)
	{
		Node<int>* temp = head_ref;
		head_ref = head_ref->next;
		head_ref->next = temp;
		temp->next = NULL;
		return head_ref;
	}
	else
	{
		Node<int>*prev = head_ref;
		Node<int>*temp = head_ref->next;
		while(temp->next != NULL)
		{
			prev = prev->next;
			temp = temp->next;
		}
		temp->next = head_ref;
		prev->next = NULL;
		head_ref = temp;
		return head_ref;
    }
}
int main()
{
	int val;
	cin>>val;
	Node<int>*head1 = new Node<int>(val);
	while(true)
	{
		cin>>val;
		if(val == -1)
			break;
		add_node(head1 , val);
	}
	Node<int>*head3 = moveToFront(head1);
	print_list(head3);
	return 0;
}
