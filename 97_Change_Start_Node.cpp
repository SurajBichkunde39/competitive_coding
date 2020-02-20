/*
Make the nth node from end of linked list as starting node.
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Line 2 : An integer N i.e. the position of new head from last node.

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4
1<=N<=10^4

Sample Input :
1 2 3 4 5 6 -1
2
Sample Output :
5 1 2 3 4 6

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

ListNode* ChangeHead(ListNode* head, int n){
	int count = 0;
	ListNode*temp = head;
	while(temp != NULL)
	{
		count++;
		temp =  temp->next;
	}
	cout<<"value of count=> "<<count<<endl;
	if(n < count)
	{
		count = count-n;
		temp = head;
		ListNode *temp1 = head->next;
		while(count != 1)
		{
			temp1 = temp1->next;
			temp = temp->next;
			count--;
		}
		temp->next = temp1->next;
		temp1->next = head;
		head = temp1;
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
	int n;
	cin>>n;
	head = ChangeHead(head , n);
	print_list(head);
	return 0;
}
