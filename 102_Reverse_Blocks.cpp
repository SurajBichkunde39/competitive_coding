/*
Given a linked list and an array of integers. Each element of the array represents a block size. 
Reverse all the blocks given in the array. Block B[i+1] starts after the last node of block B[i]. 
See the sample test case for better understanding.
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Line 2 : K, Size of block array.
Line 3 : K positive integers separated by a space.

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4
1 <= K <= 10^4
0 <= B[i] <= 10^4

Sample Input :
 1 2 3 4 5 6 7 8 9 10 11 -1
 3
 2 3 4

Sample Output :
 2 1 5 4 3 9 8 7 6 10 11
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
ListNode* ReverseBlocks(ListNode *head, int blocksize[], int length) {
	ListNode *temp = head;
	int i = 0;
	while(temp != NULL)
	{
		ListNode *start = temp;
		ListNode *initial = temp;
		int count = blocksize[i];
		int j = 0;
		int real_count = 0;
		while(temp && j<count)
		{
			temp = temp->next;
			real_count++;
			j++;
		}
		for(int k = 0;k<real_count;k++)
		{
			start = initial;
			for(int m=0;m<real_count-k-1;m++)
			{
				int val = start->data;
				start->data = start->next->data;
				start->next->data = val;
				start = start->next;
			}
		}
		i++;
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
	int length;
	cin>>length;
	int *ar;
	ar = new int[length];
	for(int i = 0;i<length;i++)
	{
		cin>>ar[i];
	}
	head1 = ReverseBlocks(head1 , ar,length);
	print_list(head1);
	return 0;
}
