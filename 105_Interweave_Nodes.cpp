/*
Given two Linked Lists. Modify them by interweaving alternate nodes. If one list is smaller then complete the task using other list. 
See the example for better understanding.
You just need to return the head of new linked lists, don't print the elements.

Input format :
Line 1 : Linked list elements of length n1 (separated by space and terminated by -1)
Line 2 : Linked list elements of length n2 (separated by space and terminated by -1)

Output format :
Updated lists

Constraints :
1 <= n1 <= 10^4
1 <= n2 <= 10^4

Sample Input :
 1 2 3 4 5 6 7 -1
 8 9 10 -1

Sample Output :
 1 9 3 5 7 
 8 2 10 4 6 

Note: For first linked list 7 is appended after 5 to keep the chain running. For second list first list is used for appending nodes after 10.

*/

#include<iostream>
using namespace std;
class ListNode{
	public:
	int data;
	ListNode* next;
};
class rettype{
	public:
	ListNode *head1;
	ListNode *head2;
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


rettype InterWeave(ListNode* head1, ListNode* head2) {
	ListNode *temp1;
	ListNode *temp2;
	ListNode *prev1;
	ListNode *prev2;
	if(head1)
		prev1 = head1;
	else
		temp1 = NULL;
	if(head2)
		prev2 = head2;
	else
		temp2 = NULL;
	if(temp1)
		temp1 = head1->next;
	if(temp2)
		temp2 = head2->next;
	bool swap = true;
	while(temp1 && temp2)
	{
		if(swap)
		{
			int val;
			val = temp1->data;
			temp1->data = temp2->data;
			temp2->data = val;
		}
		swap = !swap;
		prev1 = prev1->next;
		prev2 = prev2->next;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	ListNode *large;
	ListNode *sprev;
	ListNode *lprev;
	if(temp1)
	{
		large = temp1;
		lprev = prev1;
		sprev = prev2;
	}
	else
	{
		large = temp2;
		lprev = prev2;
		sprev = prev1;
	}
	if(!swap)
	{
		large = large->next;
		lprev = lprev->next;
	}
	//cout<<"data of large "<<large->data<<endl;
	//cout<<"data of sprev "<<sprev->data<<endl;
	//cout<<"data of lprev "<<lprev->data<<endl;
	while(large != NULL)
	{
		sprev->next = large;
		lprev->next = large->next;
		large->next = NULL;
		sprev = sprev->next;
		if(lprev->next)
			lprev = lprev->next;
		else
			break;
		if(lprev->next)
			large = lprev->next;
		else
			break;
	}
	rettype r1;
	r1.head1 = head1;
	r1.head2 = head2;
	return r1;
}
int main()
{
	ListNode*head2 = NULL;
	ListNode*head1 = NULL;
	int val;
	cin>>val;
	if(val != -1)
		head1 = newListNode(val);
	while(head1)
	{
		cin>>val;
		if(val == -1)
			break;
		add_node(head1 , val);
	}
	cin>>val;
	if(val!=-1)
		head2 = newListNode(val);
	while(head2)
	{
		cin>>val;
		if(val == -1)
			break;
		add_node(head2 , val);
	}
	rettype r1 = InterWeave(head1 , head2);
	print_list(r1.head1);
	cout<<endl;
	print_list(r1.head2);
	cout<<endl;
	return 0;
}
