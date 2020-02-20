/*
Remove duplicates from an unsorted integer linked list. Keep only the last appearance of the integer. Example:

Given: 12>11>12>21>41>43>21>12

Output: 11>41>43>21>12
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4

Sample Input :
 1 2 1 4 3 2 -1

Sample Output :
 1 4 3 2
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

ListNode* LastAppearance(ListNode* head) {
	ListNode* temp = head;
	while(temp != NULL)
	{
		ListNode* firstappear = temp;
		temp = temp->next;
		while(temp && temp->data == firstappear->data)
		{
			temp = temp->next;
		}
			
		ListNode* appear = firstappear->next;
		while(appear != NULL)
		{
			if(appear->data == firstappear->data)
			{
				if(firstappear == head)
					head = head->next;
				else
				{
					ListNode *temp = head;
					ListNode *temp1 = head->next;
					while(temp1 != firstappear)
					{
						temp1 = temp1->next;
						temp = temp->next;
					}
					temp->next = temp1->next;
				}
				firstappear = appear;
			}
			appear = appear->next;
		}
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
	
	head = LastAppearance(head);
	print_list(head);
	return 0;
}
