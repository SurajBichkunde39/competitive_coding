/*
Write a function that takes one list and divides up its nodes to create two smaller lists A and B. 
The sub lists should be made from alternating elements in the original list.
Nodes should be in the reverse order of which they occurred in the source list.
Print both linked lists in different lines.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :
Line 1 : Output Linked List 1 elements (separated by space)
Line 2 : Output Linked List 2 elements (separated by space)

Constraints :
1 <= n <= 10^4

Sample Input :
 8 2 5 9 1 4 3 7 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. 
This -1 is not part of the linked list. Size of given linked list is 8.
Sample Output :
 3 1 5 8
 7 4 9 2

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
void AlternatingSplit(Node<int>* head) {
	Node<int>*current = head;
	Node<int>*temp;
	
	Node<int>*temp1 = current;
	current = current->next;
	temp1->next = NULL;
	
	Node<int>*temp2 = current;
	current = current->next;
	temp2->next = NULL;
	
	while(current != NULL)
	{
		if(current != NULL)
		{
			temp = current;
			current = current->next;
			temp->next = temp1;
			temp1 = temp;
		}
		if(current != NULL)
		{
			temp = current;
			current = current->next;
			temp->next = temp2;
			temp2 = temp;
		}
	}
	while(temp1 != NULL)
	{
		cout<<temp1->data<<" ";
		temp1 = temp1->next;
	}
	cout<<endl;
	while(temp2 != NULL)
	{
		cout<<temp2->data<<" ";
		temp2 = temp2->next;
	}
}
int main()
{
	int val;
	cin>>val;
	Node<int>* head1 = new Node<int>(val);
	while(true)
	{
		cin>>val;
		if (val == -1)
			break;
		add_node(head1,val);
	}
	print_list(head1);
	cout<<endl;
	AlternatingSplit(head1);
	return 0;
}
