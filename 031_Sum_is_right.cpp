/*
Given a n x m matrix of integers, replace every element with sum of elements present on its right excluding current element (in current row only).
Note : Change in the given input itself. No need to print or return anything.

Input format :
Line 1 : Two space separated integers n (No. of rows) and m (No. of columns)
Next n lines : m elements of each row (separated by space).

Constraints :
1 <= n, m <= 10^4

Sample Input 1 :
1 1 
2
Sample Output 1 :
0

Sample Input 1 :
1 2
2 3
Sample Output 1 :
3 0
*/
#include<iostream>
using namespace std;
void change(int **arr,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		int col = m-1;
		int sum = 0;
		while(col != -1)
		{
			int temp = arr[i][col];
			arr[i][col] = sum;
			sum = sum + temp;
			col--;
		}
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
	change(arr,n,m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
