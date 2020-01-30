/*
Given a boolean n*m matrix (that contains 0 and 1 only), you need to return the row number which has maximum no. of 1s in it.
Rows and columns are 0-indexed based. If more than one row has same number of 1s, print the row with lowest index.

Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output format :
Line 1 : print row number

Constraints :
1 <= n, m <= 10^4

Sample Input 1 :
2 2 
0 1
1 1
Sample Output 1 :
1
*/
#include<iostream>
using namespace std;
int maxOne(int **arr,int n,int m)
{
	int row_ind = 0;
	int max_ones = 0;
	for(int i=0;i<n;i++)
	{
		int count = 0;
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] == 1)
				count++;
		}
		if(count > max_ones)
		{
			max_ones = count;
			row_ind = i;
		}
	}
	return row_ind;
}
int main()
{
	int **arr;
	int n;
	int m;
	cin>>n>>m;
	arr = new int* [n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[m];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<maxOne(arr, n , m);
	return 0;
}
