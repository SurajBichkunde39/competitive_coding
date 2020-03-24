/*
You are given with an array of integers that contain numbers in random order. Write a program to find and return the number which occurs maximum times in the given input.
If more than one element occurs same number of times in the input, return the element which is present in the input first.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Most frequent element
Constraints :
1 <= N <= 10^5
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/
#include<iostream>
#include<unordered_map> 
using namespace std;
struct node{
	int val;
	int count;
	node *next;
};
void add_hash(node**tracker , int val)
{
	int k = val % 10;
	if(!tracker[k])
	{
		node *newnode = new node();
		newnode->val = val;
		newnode->count = 1;
		newnode->next = NULL;
		tracker[k] = newnode;
	}
	else
	{
		node *temp = tracker[k];
		bool found = false;
		while(temp->next != NULL)
		{
			if(temp->val == val)
			{
				temp->count++;
				found = true;
				break;
			}
			temp = temp->next;
		}
		if (temp &&  temp->val == val)
		{
			temp->count++;
			found = true;
		}
		if(!found)
		{
			node *newnode = new node();
			newnode->val = val;
			newnode->count = 1;
			newnode->next = NULL;
			temp->next = newnode;
		}
	}
}
int highestFrequency_not(int *input, int n){
	node **tracker = new node*[10];
	for(int i=0;i<10;i++)
		tracker[i]=NULL;
	for(int i=0;i<n;i++)
	{
		add_hash(tracker,input[i]);
	}
	node *temp = tracker[0];
	int max_count = -1;
	int max_count_val = -1;
	for(int i=0;i<10;i++)
	{
		temp = tracker[i];
		while(temp)
		{
			if(temp->count > max_count)
			{
				max_count = temp->count;
				max_count_val = temp->val;
			}
			temp = temp->next;
		}
	}
	 return max_count_val;
}
int highestFrequency(int *arr, int n) 
{ 
    // Insert all elements in hash. 
    unordered_map<int, int> hash; 
    for (int i = 0; i < n; i++) 
        hash[arr[i]]++; 
  
    // find the max frequency 
    int max_count = 0, res = -1; 
    for (auto i : hash) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 
  
    return res; 
} 
int main()
{
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<mostFrequent(ar,n);
	return 0;
}
