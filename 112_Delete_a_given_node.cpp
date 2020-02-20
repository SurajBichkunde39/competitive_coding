/*
Write a function to delete a node with given data (i.e. integer x) in a doubly linked list. Return the head of new list.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Line 2 : Integer x
Output format :
Updated list elements (separated by space)
Constraints :
1 <= n <= 10^4
Sample Input :
1 2 3 4 5 6 -1
3
Note : -1 at the end of input is just a terminator representing the end of linked list. 
This -1 is not part of the linked list. Size of given linked list is 6.
Sample Output :
1 2 4 5 6
*/
#include<iostream>
using namespace std;
 template <typename T>
 class Node
 {
	public:
    T data;
    Node<T>* next, *arbit;
    Node(T data)
    {
        this->data=data;
        next=NULL;
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

Node<int>* deleteNode(Node<int> *head, int x) {
	if(head->data == x)
	{
		head = head->next;
	}
	else
	{
        Node<int>*prev = head;
		Node<int>*temp = head->next;
		while(temp->next != NULL)
		{
			if(temp->data == x)
			{
                prev->next = temp->next;
                temp = NULL;
				break;
			}
            prev = prev->next;
			temp = temp->next;
		}
		if(temp && temp->data == x)
		{
            //cout<<"i mean why i am here"<<endl;
            prev->next = NULL;
			//temp->prev->next = NULL;
		}
	}
    return head;
}
int main()
{
	int val;
	cin>>val;
	ListNode*head1 = newListNode(val);
	while(true)
	{
		cin>>val;
		if(val == -1)
			break;
		add_node(head1 , val);
	}
	int x;
	cin>>x;
	head1 = deleteNode(head1,x);
	print_list(head1);
	return 0;
}
