/*
Given a n*m matrix, print the rows in reverse order. Do this for every row.

Input format :
Line 1 : n and m(space separated positive integers)
Next n lines : m integers of every row (separated by space)
Output format :
Print every row in new line (row elements separated by space)

Constraints :
1 <= n, m <= 10^4

Sample Input 1 :
2 2
1 2
3 4
Sample Output 1 :
2 1
4 3
*/
#include<iostream>
using namespace std;
void reversePrint(int **arr,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
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
	reversePrint(arr, n , m);
	return 0;
}
