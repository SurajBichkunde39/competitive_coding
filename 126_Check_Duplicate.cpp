/*
Given an integer array, return true if the array contains duplicate elements within K distance from each other otherwise return false.
Input format :
Line 1 : Integer N 
Line 2 : N integers separated be a single space
Line 3 : Integer K
Output Format :
 Boolean
Constraints :
 1 <= N <= 10^4
 1 <= K <= 10^4
Sample Input :
5
3 4 9 4 2 
2 
Sample Output :
true
*/
#include<iostream>
#include<set>
using namespace std;
bool CheckDuplicateWithinK(int arr[], int n, int k){
	for(int i=0;i<n;i++)
	{
		set<int>tracker;
		tracker.insert(arr[i]);
		int count = 0;
		pair< set<int>::iterator,bool> ptr;
		while(count < k && count+i<n)
		{
			ptr = tracker.insert(arr[i+count]);
			if(!ptr.second)
				return true;
			count++;
		}
		count = 0;
		while(count > k && i-count >= 0)
		{
			ptr = tracker.insert(arr[i-count]);
			if(!ptr.second)
				return true;
			count++;
		}
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	int *ar = new int[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	int k;
	cin>>k;
	cout<<CheckDuplicateWithinK(ar,n,k);
	return 0;
}
