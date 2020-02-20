/*
Find area under the curve along x axis. The curve is represented by a LL having only vertical and horizontal lines. 
X coordinate will either be non decreasing or non increasing form start to end of linked list.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1). Each node has two parts (x and y coordinates). 
Example: x1 y1 x2 y2 x3 y3 -1
Output format :
Print area of curve along X axis.
Constraints :
1 <= n <= 10^2
Sample Input :
 1 10 5 10 7 10 7 5 20 5 40 5 40 7 42 7 -1
Sample Output :
 239
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
void FindArea(ListNode *head) {
	ListNode* temp = head;
	int area = 0;
	while(temp != NULL)
	{
		ListNode* first_point = temp;
		if(temp->next && temp->next->Y == temp->Y)
		{
			ListNode *current = temp->next;
			while(current->next && current->next->Y == first_point->Y)
				current = current->next;
			temp = current;
			int diff = first_point->X > current->X ? first_point->X - current->X :  current->X - first_point->X;
			area += diff * current->Y;
		}
		else if(temp->next && temp->next->X == first_point->X)
		{
			ListNode *current = temp->next;
			while(current->next && current->next->X == first_point->X)
				current = current->next;
			temp = current;
		}
		else
		{
			temp = temp->next;
		}
	}
	cout<<area<<endl;
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
	FindArea(head);
	return 0;
}
