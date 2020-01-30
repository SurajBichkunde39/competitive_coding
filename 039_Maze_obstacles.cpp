/*
Given a n*m maze with obstacles, count and return number of paths to reach right-bottom cell from top-left cell. 
A cell in given maze has value -1 if it is a blockage or dead end, else 0. 
From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only.

Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output format :
Line 1 : print row number

Constraints :
1 <= n, m <= 10^4

Sample Input 1 :
2 2
0 0
0 0
Sample Output 1 :
2

Sample Input 2 :
2 2
0 -1
0  0
Sample Output 2 :
1

*/
#include<iostream>
using namespace std;
int countPaths(int **arr,int n,int m)
{
	if(arr[0][0] == -1)
		return 0;
	else
	{
		arr[0][0] = 1;
		arr[n-1][m-1] = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[i][j] != -1)
				{
					int right = 0;
					int up = 0;
					if(i>0)
					{
						if(arr[i-1][j] != -1)
						{
							up = arr[i-1][j];
						}
					}
					if(j>0)
					{
						if(arr[i][j-1] != -1)
						{
							right = arr[i][j-1];
						}
					}
					arr[i][j] = arr[i][j]+up + right;
				}
			}
		}
	}
	return arr[n-1][m-1];
}

int main()
{
	int n , m;
	cin>>n>>m;
	int **arr;
	arr = new int*[n];
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
	cout<<countPaths(arr,n,m);
	return 0;
}
