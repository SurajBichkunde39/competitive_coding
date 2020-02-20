/*
Given a linked list such that each node represents a digit. Construct the maximum number possible from the given digits.
You just need to print the maximum Integer that can be formed.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output format :
Maximum Number
Constraints :
1 <= n <= 10^4
Sample Input :
 1 2 2 0 9 -1
Sample Output :
 92210
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

void FindLargestNum(ListNode *head) {
	int *hash_table = new int[10];
	for(int i=0;i<10;i++)
		hash_table[i] = 0;
	ListNode *temp = head;
	while(temp != NULL)
	{
		hash_table[temp->data]++;
		temp = temp->next;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<hash_table[i];j++)
		{
			cout<<i;
		}
	}
}
int main()
{
	int val;
	cin>>val;
	ListNode *head = NULL;
	if(val != -1)
		head = newListNode(val);
	while(head)
	{
		cin>>val;
		if(val == -1)
			break;
		add_node(head,val);
	}
	FindLargestNum(head);
	//print_list(head);
	//cout<<endl;
	return 0;
}
