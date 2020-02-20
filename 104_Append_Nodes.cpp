/*
Given an Integer Linked List. After every M nodes add next N nodes and add this sum to linked list. 
Do this till end of Linked List. See the sample input for better explanation.
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Line 2 : Integer N
Line 3 : Integer M

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4
1 <= N <= 10^4
1 <= M <= 10^4

Sample Input :
 1 2 3 4 5 6 7 8 9 10 11 12 -1
 2
 3
Sample Output :
1 2 3 4 5 9 6 7 8 9 10 19 11 12 
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
ListNode *AddNafterMnodes(ListNode *head, int N, int M) {
	ListNode *temp = head;
	while(temp)
	{
		for(int i = 0;i<M;i++)
		{
			if(temp)
				temp = temp->next;
			else
				return head;
		}
		int k = N;
		ListNode *prev = temp;
		temp = temp->next;
		int j = 0;
		int sum = prev->data;
		while(j != k-1)
		{
			if(temp)
			{
				sum += temp->data;
				prev = prev->next;
				temp = temp->next;
			}
			else
				break;
			j++;
		}
		if(j == k-1)
		{
			ListNode *newnode = newListNode(sum);
			ListNode *nextnode = prev->next;
			prev->next = newnode;
			newnode->next = nextnode;
		}
		if(!temp)
		{
			ListNode *newnode = newListNode(sum);
			prev->next = newnode;
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
	int n , m;
	cin>>n>>m;
	head1 = AddNafterMnodes(head1 , n,m);
	print_list(head1);
	return 0;
}
