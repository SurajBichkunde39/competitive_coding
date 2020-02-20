/*
Given two sorted linked lists. Create a linked list with common elements such that all common odd elements are before common even elements.
You just need to return the head of new linked list formed, don't print the elements.

Note: The relative order of even and odd nodes should not change.

Input format :
Line 1 : Linked list elements of length n1 (separated by space and terminated by -1)
Line 2 : Linked list elements of length n2 (separated by space and terminated by -1)

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n1 <= 10^4
1 <= n2 <= 10^4

Sample Input :
 1 2 3 4 5 7 8 -1
 2 4 4 7 8 10 -1
Sample Output :
7 2 4 8

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
ListNode* AlterList(ListNode* head1, ListNode* head2) {
	ListNode *head3 = NULL;
	ListNode *list1 = head1;
	//odd
	while(list1 != NULL)
	{
		if(list1->data %2 != 0)
		{
			ListNode *list2 = head2;
			while(list2 != NULL)
			{
				if(list2->data == list1->data)
				{
					if(head3 == NULL)
					{
						head3 = newListNode(list1->data);
					}
					else
					{
						ListNode *temp = head3;
						ListNode *newnode = newListNode(list1->data);
						while(temp->next != NULL)
							temp = temp->next;
						temp->next = newnode;
					}
					break;
				}
				else if(list2->data > list1->data)
					break;
				else
				{
					int val = list2->data;
					list2 = list2->next;
					while(list2 && list2->data == val)
						list2 = list2->next;
				}
			}
		}
		int val = list1->data;
		list1 = list1->next;
		while(list1 && list1->data == val)
			list1 = list1->next;
	}
	//even
	list1 = head1;
	while(list1 != NULL)
	{
		if(list1->data %2 == 0)
		{
			ListNode *list2 = head2;
			while(list2 != NULL)
			{
				if(list2->data == list1->data)
				{
					if(head3 == NULL)
					{
						head3 = newListNode(list1->data);
					}
					else
					{
						ListNode *temp = head3;
						ListNode *newnode = newListNode(list1->data);
						while(temp->next != NULL)
							temp = temp->next;
						temp->next = newnode;
					}
					break;
				}
				else if(list2->data > list1->data)
					break;
				else
				{
					int val = list2->data;
					list2 = list2->next;
					while(list2 && list2->data == val)
						list2 = list2->next;
				}
			}
		}
		int val = list1->data;
		list1 = list1->next;
		while(list1 && list1->data == val)
			list1 = list1->next;
	}
	return head3;
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
	cin>>val;
	ListNode*head2 = newListNode(val);
	while(true)
	{
		cin>>val;
		if(val == -1)
			break;
		add_node(head2 , val);
	}
	ListNode*head = AlterList(head1,head2);
	print_list(head);
	return 0;
}
