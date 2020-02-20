/*
Given a linked list l1->l2->l3->l4->and so on. Write a program that will swap pairs (l1, l2), (l3, l5), (l6, l9) ......etc.
You just need to return the head of new linked list, don't print the elements.
Note: If pair of a node does not exist then leave the node as it is.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4

Sample Input :
 1 2 3 4 5 -1
Sample Output :
 2 1 5 4 3
*/
#include<iostream>
using namespace std;
class ListNode{
	public:
	int data;
	ListNode* next;
};

ListNode* newListNode(int data){
	ListNode *temp = new ListNode;
    	temp->data = data;
    	temp->next = NULL;
    	return temp;
}
void add_node(ListNode*head , int data)
{
	ListNode* newnode = newListNode(data);
	ListNode* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
void print_list(ListNode* head)
{
	ListNode* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
ListNode* PairSwap(ListNode* head){
	ListNode*temp = head;
	int swap_count = 2;
	while(temp != NULL)
	{
		ListNode* start = temp;
		int j = 1;
		bool reached_end = false;
		while(j != swap_count)
		{
			temp = temp->next;
			if(!temp)
			{
				reached_end = true;
				break;
			}
			j++;
		}
		if(reached_end)
			break;
		ListNode* end = temp;
		int t = start->data;
        start->data = end->data;
        end->data = t;
		temp = temp->next;
		swap_count++;
	}
	return head;
}


int main()
{
	int val;
	cin>>val;
	ListNode*head = newListNode(val);
	while(true)
	{
		cin>>val;
		if(val == -1)
			break;
		add_node(head , val);
	}
	//print_list(head);
	//cout<<endl;
	
	head = PairSwap(head);
	print_list(head);
	return 0;
}
