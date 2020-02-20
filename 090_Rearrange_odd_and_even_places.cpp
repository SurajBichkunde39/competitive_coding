/*
Rearrange and return a linked list in such a way that all odd position nodes are together and all even positions node are together
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4

Sample Input :
 1 2 3 4 5 6 7 8 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. 
This -1 is not part of the linked list. Size of given linked list is 4.
Sample Output :
 1 3 5 7 2 4 6 8

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
Node<int> *rearrangeEvenOdd(Node<int> *head) {
    	Node<int>*head1,*temp1;
	Node<int>*head2,*temp2;
	Node<int>*current=head;
	head1 = current;
	current = current->next;
	head2 = current;
	current = current->next;
	temp1 =  head1;
	temp2 = head2;
	bool end_at_stage1 = true;
	while(current != NULL)
	{
		if(current != NULL)
		{
			temp1->next = current;
			current = current->next;
			temp1 = temp1->next;
			end_at_stage1 = true;
		}
		if(current != NULL)
		{
			temp2->next = current;
			current = current->next;
			temp2=temp2->next;
			end_at_stage1 = false;
		}
	}
	if(end_at_stage1)
	{
		temp2->next = NULL;
        temp1->next = head2;
	}
	else
	{
		//temp1->next = NULL;
        temp1->next = head2;
	}
	return head1;
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
	Node<int>*newhead = rearrangeEvenOdd(head1);
	print_list(newhead);
	return 0;
}
