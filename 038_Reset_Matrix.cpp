/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0. Do it in place.
Note : You don't need to print the matrix. Just change in the given input.

Input format :

Line 1 : No. of rows & No. of columns (separated by space)
Line 2 : Row 1 elements (separated by space)
Line 3 : Row 2 elements (separated by space)
Line 4 : and so on

Sample Input 1 :
3 3
1 0 1
1 1 1 
1 1 1
Sample Output 1 :
0 0 0
1 0 1
1 0 1
*/
#include<iostream>
using namespace std;
void make_change(int **input , int row , int col , int n , int m)
{
	for(int i=0;i<n;i++)
	{
		input[i][col] = 0;
	}
	for(int j=0;j<m;j++)
	{
		input[row][j] = 0;
	}
}
void makeRowsCols0_app1(int **input, int rows, int cols) {
	//this is simple approch
	//the problem with this is , ones it goes deep it won't cansider outside zeros
	int i = 0;
	int j = 0;
	int col_trans = 0;
	while(i<rows && j<cols)
	{
		//cout<<"row: "<<i<<" col: "<<j<<endl;
		if(input[i][j] == 0)
		{
			make_change(input , i , j , rows, cols);
			i++;
			j++;
			col_trans = j;
		}
		else
		{
			if(j == cols-1)
			{
				j = col_trans;
				i++;
			}
			else if(j<cols)
			{
				j = (j+1)%cols;
			}
		}
	}
}
#include<vector>
void makeRowsCols0(int **input , int rows , int cols)
{
	vector<int> row;
	vector<int> col;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(input[i][j] == 0)
			{
				row.push_back(i);
				col.push_back(j);
			}
		}
	}
	vector<int>::iterator it = row.begin();
	vector<int>::iterator it1 = col.begin();
	while(it != row.end())
	{
		make_change(input ,*it,*it1 , rows , cols);
		it++;
		it1++;
	}
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
	makeRowsCols0(arr,n,m);
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
