/*
Given an integer LL. Modify the LL by adding continuous k nodes and inserting a new node after every k nodes indicating their sum. 
See the sample input for better explanation.
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Line 2 : Integer k 

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4
1 <= K <= 10^4

Sample Input :
 1 2 3 4 5 6 7 -1
 3
Sample Output :
 1 2 3 6 4 5 6 15 7 7 
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
ListNode* AddKNodes(ListNode *head, int k) {
	ListNode *temp = head;
	while(temp)
	{
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
		if(!temp && j==k-1)
		{
			cout<<"adding sum at last"<<sum<<endl;
			ListNode *newnode = newListNode(sum);
			prev->next = newnode;
		}
		else if(j == k-1)
		{
			cout<<"adding sum in between"<<sum<<endl;
			ListNode *newnode = newListNode(sum);
			ListNode *nextnode = prev->next;
			prev->next = newnode;
			newnode->next = nextnode;
		}
		else
			break;
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
	int n;
	cin>>n;
	head1 = AddKNodes(head1 , n);
	print_list(head1);
	return 0;
}
