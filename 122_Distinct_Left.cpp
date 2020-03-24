/*
Find the number of distinct elements left after removing K maximum elements from the given array.
Example :
Ar = {5, 7, 5, 5, 1, 2, 2}, k = 3
output = 3 (remove 7, 5 and 5)
Input format :
Line 1 : Integer N 
Line 2 : N integers separated be a single space
Line 3 : Integer K
Output Format :
 Distinct_Elements_Left
Constraints :
 0 <= N <= 10^5
 0 <= K <= 10^5
Sample Input :
7
5 7 5 5 1 2 2 
3
Sample Output :
3
*/
#include<iostream>
#include<map>
using namespace std;
int FindDistinctCount(int *arr, int n,int k) {
	 map<int,int>dis_count;
	 for(int i=0;i<n;i++)
	 {
		 auto it = dis_count.find(arr[i]);
		 if(it == dis_count.end())
			dis_count.insert(make_pair(arr[i],1));
		else
			it->second++;
	}
	while(k!=0)
	{
		auto it = dis_count.end();
		it--;
		if(k >= it->second)
		{
			k-=it->second;
			dis_count.erase(it);
		}
		else
		{
			it->second -= k;
			k=0;
		}
	}
	return dis_count.size();
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
	cout<<FindDistinctCount(ar,n,k);
	return 0;
}
