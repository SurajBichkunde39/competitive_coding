.*
Given a LL such that each node represent a single digit. Return an integer x, 
x is the sum of the numbers formed by 1st half and reverse of 2nd half of LL(consider middle element to be part of 1st half).
Example:
LL: 1-2-3-4-5-5-6
Output: 1889
You just need to return the number

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :
Integer x

Constraints :
1 <= n <= 17

Sample Input :
 5 2 4 1 8 -1
Sample Output :
 605
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
int HalfAddRev(ListNode* head) {
	int len = 0;
	ListNode *temp = head;
	while(temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	int count = len %2 == 0 ? len/2 : len/2+1;
	int multiplier = 1;
	int sec_multiplier = 1;
	for(int i =1;i<count;i++)
	{
		multiplier *= 10;
		
	}
	temp = head;
	int j = 0;
	int sum1 = 0;
	while(j!=count)
	{
		sum1 += temp->data*multiplier;
		multiplier /= 10;
		temp = temp->next;
		j++;
	}
	int sum2 = 0;
	while(temp)
	{
		sum2 += temp->data*sec_multiplier;
		sec_multiplier *= 10;
		temp = temp->next;
	}
	//cout<<"sum1 "<<sum1<<endl;
	//cout<<"sum2 "<<sum2<<endl;
	return sum1 + sum2;
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
	cout<<HalfAddRev(head);
	cout<<endl;
	return 0;
}
