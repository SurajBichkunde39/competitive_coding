/*
Given a square matrix in form of linked list with each node having right and down pointer. 
Modify it in a singly linked list which should only be connected using right pointer.

Example
1->2->3
|  |  |
4->5->6
|  |  |
7->8->9
| is an arrow down pointer
You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Size of the square matrix n
Line 2 : n*n Integers separated by single space (matrix is entered row wise) 

Output format :
Updated list elements (separated by space)

Constraints :
1 <= n <= 10^2

Sample Input :
3
1 2 3 4 5 6 7 8 9 
Sample Output :
1 4 7 8 9 2 5 6 3

*/
#include<iostream>
using namespace std;

class ListNode{
	public:
	int data;
	ListNode* right;
	ListNode* down;
};

ListNode* newListNode(int data){
	ListNode *temp = new ListNode;
    	temp->data = data;
    	temp->right = NULL;
    	temp->down = NULL;
    	return temp;
}

ListNode* ModifyMatrix(ListNode *head){
	ListNode* temp = head;
    int n = 0;
    while(temp)
    {
        n++;
        temp = temp->right;
    }
    temp = head;
    int turn = 0;
    while(temp)
    {
        ListNode *inner_temp = temp;
        cout<<inner_temp->data<<" ";
        for(int i=1;i<n-turn;i++)
        {
            inner_temp = inner_temp->down;
             cout<<inner_temp->data<<" ";
        }
        inner_temp = inner_temp->right;
        while(inner_temp)
        {
            cout<<inner_temp->data<<" ";
            inner_temp = inner_temp->right;
        }
        temp = temp->right;
        turn++;
    }
}
int main()
{
	return 0;
}
