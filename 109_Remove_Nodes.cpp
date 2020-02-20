/*
Remove nodes at position 2^nth from linked list where n can be 0, 1, 2 and so on.
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4

Sample Input :
3 4 5 6 7 8 -1
Sample Output :
5 7 8
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
ListNode* RemoveNpowNodes(ListNode* head) {
	if(head)
	{
		if(head->next)
		{
			head = head->next;
			if(head->next)
			{
				head = head->next;
				int count = 4;
				int tracker = 4;
				ListNode *prev = head;
				ListNode *temp = NULL;
				if(head->next)
					temp = head->next;
				while(temp != NULL)
				{
					if(tracker == count)
					{
						if(temp->next == NULL)
						{
							prev->next = NULL;
							temp = NULL;
						}
						else
						{
							tracker *= 2;
							count+=2;
							prev->next = temp->next;
							prev = prev->next;
							if(prev->next)
								temp = prev->next;
							else
								temp = NULL;
						}
					}
					else
					{
						count++;
						temp = temp->next;
						prev = prev->next;
					}
				}
			}
		}
	}				
	return head;
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
	head = RemoveNpowNodes(head);
	print_list(head);
	cout<<endl;
	return 0;
}
