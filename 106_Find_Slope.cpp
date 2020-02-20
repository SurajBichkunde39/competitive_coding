/*
Find min and max slope if all the nodes of the linked list represent coordinates on a Cartesian plane. Example:
LL: P1(x1, y1) -> P2(x2, y2) -> P3(x3, y3) -> P4(x4, y4)

Output:
Max (slope(P1,P2), slope(P2,P3), slope(P3, P4))
Min (slope(P1,P2), slope(P2,P3), slope(P3, P4))

You just need to print the starting node for min and max slope in different lines. 
For example if slope(P1,P2) is max then print x1 and y1 seperated by single space. 
In case of more than one possible solution print the first occurring solution.

Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1). Each node has two parts (x and y coordinates). Example: x1 y1 x2 y2 x3 y3 -1

Output format :
MIN: Xk Yk
MAX: Xm Ym

Constraints :
1 <= n <= 10^4

Sample Input :
 865 45 287 75 309 368 77 60 953 45 -1

Sample Output :
 MIN: 865 45
 MAX: 287 75
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
void add_node(ListNode *head, int x, int y)
{
	ListNode *temp = head;
	ListNode *newnode = new ListNode(x,y);
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
void print_list(ListNode *head)
{
	ListNode *temp = head;
	while(temp != NULL)
	{
		cout<<temp->X<<","<<temp->Y<<" ";
		temp = temp->next;
	}
}

void FindMinMax(ListNode *head) {
	ListNode *temp = head;
	ListNode *temp1;
	if(temp)
	{
		if(temp->next)
		{
			//cout<<temp->X<<","<<temp->Y<<" ";
			temp1 = temp->next;
			bool got_min_slope = false;
			bool got_max_slope = false;
			double min_slope = 0;
			double max_slope = 0;
			ListNode *min = temp;
			ListNode *max = temp;
			if(temp1->X == temp->X)
			{
				got_max_slope = true;
				max = temp;
			}
			if(temp->Y == temp1->Y)
			{
				got_min_slope = true;
				min = temp;
			}
			if(!got_min_slope)
			{
				min_slope = float((temp->Y - temp1->Y))/float((temp->X - temp1->X));
				min = temp;
			}
			if(!got_max_slope)
			{
				max_slope = float((temp->Y - temp1->Y))/float((temp->X - temp1->X));
				max = temp;
			}
			temp = temp->next;
			temp1 = temp1->next;
			//cout<<" min_slope "<<min_slope<<" max slope "<<max_slope<<endl;
			while(temp1!= NULL)
			{
				//cout<<temp->X<<","<<temp->Y<<" ";
				int cur_slope;
				if(!got_min_slope)
				{
					if(temp->Y == temp1->Y)
					{
						got_min_slope = true;
						min = temp;
					}
					else
					{
						cur_slope = float((temp->Y - temp1->Y))/float((temp->X - temp1->X));
						if(min_slope > cur_slope)
						{
							min = temp;
							min_slope = cur_slope;
						}		
					}
				}
				
				if(!got_max_slope)
				{
					if(temp->X == temp1->X)
					{
						got_max_slope = true;
						max = temp;
					}
					else
					{
						cur_slope = float((temp->Y - temp1->Y))/float((temp->X - temp1->X));
						if(max_slope < cur_slope)
						{
							max = temp;
							max_slope = cur_slope;
						}
					}
				}
				//cout<<" min_slope "<<min_slope<<" max slope"<<max_slope<<endl;
				temp = temp->next;
				temp1 = temp1->next;
			}
			cout<<"MIN: "<<min->X<<" "<<min->Y<<endl;
			cout<<"MAX: "<<max->X<<" "<<max->Y<<endl;
		}
		else
		{
			cout<<"MIN: "<<temp->X<<" "<<temp->Y<<endl;
			cout<<"MAX: "<<temp->X<<" "<<temp->Y<<endl;
		}
	}
}
int main()
{
	ListNode *head;
	int x,y;
	cin>>x>>y;
	if(x == -1)
		head = NULL;
	else
		head = new ListNode(x,y);
	while(head)
	{
		cin>>x>>y;
		if(x == -1)
			break;
		add_node(head , x, y);
	}
	FindMinMax(head);
	return 0;
}
// 865 45 287 75 309 368 77 60 953 45 -1 -1
// 51 27 344 4 15 96 75 84 91 910 -1 -1

