/*
Given a linked list write a function to return the inversion count for the list. Inversion count - how far the list is from being sorted.
Two nodes n1 and n2 form an inversion if n1.data > n2.data and n2 appears after n1.
You just need to return the count value.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output format :
Inversion count 
Constraints :
1 <= n <= 10^4
Sample Input :
 3 2 1 5 4 -1
Sample Output :
 4
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
int InversionCount(ListNode* head) {
	 ListNode *temp = head;
	 int count = 0;
	 while(temp != NULL)
	 {
		 ListNode *itemp = temp->next;
		 while(itemp)
		 {
			 if(itemp->data < temp->data)
				count++;
			itemp = itemp->next;
		}
		temp = temp->next;
	}
	return count;
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
	cout<<InversionCount(head1);
	return 0;
}
