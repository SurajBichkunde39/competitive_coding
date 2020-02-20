/*
Given a sorted doubly linked list of positive distinct elements, 
the task is to print pairs in input list whose sum is equal to given integer x. 
Try doing it without using any extra space.
If there are no such pairs, you are not required to print anything. Order of pairs doesn't matter.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Line 2 : Integer x

Output format :
Print pair elements separated by space. Different pairs in different lines.

Constraints :
1 <= n <= 10^4

Sample Input :
 1 2 3 4 5 6 -1
 5

Sample Output :
 1 4
 2 3

*/
#include<iostream>
using namespace std;
 template <typename T>
 class Node {
    public:
        T data;
        Node* next;
        Node* prev;
 
        Node(T data) {
            next = NULL; prev=NULL;
            this->data = data;
        }
 
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
 };

void add_node(Node<int>*head , int val)
{
	Node<int>*newnode = new Node<int>(val);
	if(head == NULL)
		head = newnode;
	else
	{
		Node<int>*temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		newnode->prev = temp;
		temp->next = newnode;
	}
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
void pairSum(Node<int>* head, int x) {
	Node<int>*temp = head;
	while(temp != NULL && temp->data <= x)
	{
		int expected_val = x - temp->data;
		Node<int>*inner_temp = temp->next;
		while(inner_temp != NULL && inner_temp->data <= expected_val)
		{
			if(inner_temp->data == expected_val)
			{
				cout<<temp->data<<" "<<inner_temp->data<<endl;
				break;
			}
			inner_temp = inner_temp->next;
		}
		temp = temp->next;
	}
}

int main()
{
	int val;
	cin>>val;
	Node<int>*head = new Node<int>(val);
	while(true)
	{
		cin>>val;
		if(val == -1)
			break;
		add_node(head,val);
	}
	print_list(head);
	cout<<endl;
	int x;
	cin>>x;
	pairSum(head,x);
	return 0;
}
