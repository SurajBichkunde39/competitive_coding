/*
Given two linked lists sorted in increasing order. Merge them such a way that the result list is in decreasing order (reverse order).
Try solving without reverse, with O(1) auxiliary space (in-place) and only one traversal of both lists. You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list 1 elements of length n (separated by space and terminated by -1)
Line 2 : Linked list 2 elements of length m (separated by space and terminated by -1)

Output format :
Merged list elements (separated by space)

Constraints :
1 <= n, m <= 10^4

Sample Input :
 2 5 8 12 -1
 3 6 9 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. 
Size of 1st linked list is 4 and that of 2nd linked list is 3.
Sample Output :
 12 9 8 6 5 3 2
*/
#include<iostream>
using namespace std;
 //Following is the Node structure already written.
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

Node<int>* merge_reverse(Node<int>* head1,Node<int>* head2) {
	Node<int>*temp1 = head1;
	Node<int>*temp2 = head2;
	Node<int>*head3;
	//add the first node to the new list
	if(temp1->data < temp2->data)
	{
		head3 = new Node<int>(temp1->data);
		temp1 = temp1->next;
	}
	else
	{
		head3 = new Node<int>(temp2->data);
		temp2 = temp2->next;
	}
	while(temp1 != NULL && temp2 != NULL)
	{
		Node<int>* temp;
		if(temp1->data < temp2->data)
		{
			temp = new Node<int>(temp1->data);
			temp1 = temp1->next;
		}
		else
		{
			temp = new Node<int>(temp2->data);
			temp2 = temp2->next;
		}
		temp->next = head3;
		head3 = temp;
	}
	if(temp1 != NULL)
	{
		while(temp1 != NULL)
		{
			Node<int>* temp = new Node<int>(temp1->data);
			temp->next = head3;
			head3 = temp;
			temp1 = temp1->next;
		}
	}
	if(temp2 != NULL)
	{
		while(temp2 != NULL)
		{
			Node<int>* temp = new Node<int>(temp2->data);
			temp->next = head3;
			head3 = temp;
			temp2 = temp2->next;
		}
	}
    return head3;
}
int main()
{
	Node<int>*head1 = new Node<int>(2);
	Node<int>*head2 = new Node<int>(1);
	for(int i = 0;i<3;i++)
	{
		int val;
		cin>>val;
		add_node(head1 , val);
	}
	for(int i=0;i<3;i++)
	{
		int val;
		cin>>val;
		add_node(head2,val);
	}
	print_list(head1);
	cout<<endl;
	print_list(head2);
	cout<<endl;
	Node<int>*head3 = merge_reverse(head1,head2);
	print_list(head3);
	return 0;
}
