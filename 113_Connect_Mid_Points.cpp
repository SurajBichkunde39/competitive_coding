/*
Connect mid points of all line segments. The LL given has only vertical and horizontal lines. 
In case middle point is (7,7.5) take it as (7,7). Example:
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1). 
Each node has two parts (x and y coordinates). Example: x1 y1 x2 y2 x3 y3 -1
Output format :
(M1x,M1y)(M2x,M2y) and so on
Constraints :
1 <= n <= 10^4
Sample Input :
 10 13 20 13 20 26 -1
Sample Output :
 (15,13)(20,19)

*/

#include<iostream>
using namespace std;
class ListNode{
	public:
	int X, Y;
	ListNode *next;
	ListNode(int X, int Y)
	{
		this->X = X;
		this->Y = Y;
		next = NULL;
	}
};
void add_node(ListNode *head , int X,int Y)
{
	ListNode *newnode = new ListNode(X,Y);
	ListNode *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
}
void print_list(ListNode *head)
{
	ListNode *temp = head;
	while(temp != NULL)
	{
		cout<<"("<<temp->X<<","<<temp->Y<<")";
		temp = temp->next;
	}
}
ListNode* ConnectMidPts(ListNode *head) {
	ListNode* temp = head;
	ListNode *new_list = new ListNode(-1,-1);
	while(temp != NULL)
	{
		ListNode* first_point = temp;
		if(temp->next && temp->next->Y == temp->Y)
		{
			ListNode *current = temp->next;
			while(current->next && current->next->Y == first_point->Y)
				current = current->next;
			temp = current;
			add_node(new_list , (first_point->X+current->X)/2 , first_point->Y);
		}
		else if(temp->next && temp->next->X == first_point->X)
		{
			ListNode *current = temp->next;
			while(current->next && current->next->X == first_point->X)
				current = current->next;
			temp = current;
			add_node(new_list,first_point->X, (first_point->Y+current->Y)/2);
			temp = current;
		}
		else
		{
			temp = temp->next;
		}
	}
	return new_list->next;
}
int main()
{
	int X,Y;
	ListNode *head = NULL;
	cin>>X>>Y;
	head = new ListNode(X,Y);
	while(head)
	{
		cin>>X;
		if(X==-1)
			break;
		cin>>Y;
		add_node(head,X,Y);
	}
	head = ConnectMidPts(head);
	print_list(head);
	return 0;
}
//0 10 1 10 5 10 7 10 7 5 20 5 40 5 -1
