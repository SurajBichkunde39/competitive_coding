/*
Given a singly linked list L : L0→L1→…→Ln-1→Ln . Rearrange the nodes in the list so that the new formed list is : 
L0→Ln→L1→Ln-1→L2→Ln-2→…
You are required do this in-place without altering the nodes' values.
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4

Sample Input :
2 5 8 12 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 4.

Sample Output :
2 12 5 8

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

Node<int>* rearrange(Node<int> *head){
	//L0→Ln→L1→Ln-1→L2→Ln-2→…
	int count = 0;
	Node<int>*temp = head;
	Node<int>*current = head;
	while(temp->next!= NULL)
	{
		count++;
		temp = temp->next;
	}
	Node<int>* newcurrent = current->next;
	current->next = temp;
	temp->next = newcurrent;
	current = newcurrent;
	int end_val = count%2;
	cout<<count<<endl;
	count -= 2;
	while(count != end_val)
	{
		int i = 0;
		temp = current;
		while( i!= count)
		{
			i++;
			temp = temp->next;
		}
		newcurrent = current->next;
		current->next = temp;
		temp->next = newcurrent;
		current = newcurrent;
		count -= 2;
	}
    if(end_val == 1)
		current->next->next = NULL;
	else
		current->next = NULL;
    return head;
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
	Node<int>*newhead = rearrange(head1);
	print_list(newhead);
	cout<<endl;
	return 0;
}
