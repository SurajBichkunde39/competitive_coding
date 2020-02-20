/*
Given a singly linked list, delete middle node of the linked list. For example, if given linked list is 1 -> 2 -> 3 -> 4 -> 5 then 
linked list should be modified to 1 -> 2 -> 4 -> 5. If size of input list is even, delete the first middle node.
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
1 2 4 5 6

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
Node<int>* deleteMid(Node<int> *head) {
    //count number of elements
    Node<int>* temp = head;
    int count = 0;
    while(temp != NULL)
    {
		temp = temp->next;
		count++;
	}
	int delete_count = count %2==0 ? count/2 : count/2+1;
	Node<int>*prev = head;
	temp = head->next;
	delete_count-=2;
	cout<<delete_count<<endl;
	if(delete_count >= 0){
		while(delete_count != 0)
		{
			temp = temp->next;
			prev = prev->next;
			delete_count--;
		}
		prev->next= temp->next;
	}
	else
	{
		head = head->next;
	}
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
	Node<int>*newhead = deleteMid(head1);
	cout<<"Printin arranged list"<<endl;
	print_list(newhead);
	cout<<endl;
	return 0;
}
