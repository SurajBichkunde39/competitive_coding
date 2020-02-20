/*
Rotate linked list by n positions in clockwise direction. You are given a linked list and an integer n, return the n-rotated linked list.
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length L (separated by space and terminated by -1)
Line 2 : Integer n

Output format :
Updated list elements (separated by space)

Constraints :
1 <= L <= 10^4

Sample Input :
1 2 3 4 5 6 -1
2
Note : -1 at the end of input is just a terminator representing the end of linked list. 
This -1 is not part of the linked list. Size of given linked list is 6.
Sample Output :
5 6 1 2 3 4

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
Node<int> *rotate( Node<int> *head, int x){
	int count = 0 ;
	Node<int>*temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	//make it circular
	temp->next = head;
	x = x % (count + 1);
	int go = count > x ? count - x : x - count;
	temp = head;
	while(go != 0)
	{
		temp = temp->next;
		go--;
	}
	head = temp->next;
	temp->next = NULL;
	return head;
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
	int n;
	cin>>n;
	Node<int>*head3 = rotate(head1 , n);
	print_list(head3);
	return 0;
}


