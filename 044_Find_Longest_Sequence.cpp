/*
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) 
such that all cells along the path are in increasing order with a difference of 1. 
Only 4 possible movements allowed i.e up, down, left , and right.
See the sample input.

Input format :
Line 1 : Size of the matrix N
Line 2 : NXN elements of the matrix separated by space 

Output Format :
 Return the maximum length

Constraints :
 1 <= N <= 10^3

Sample Input :
3
9 1 3 
7 4 2 
6 5 0

Sample Output :
4

*/
#include<iostream>
using namespace std;
int finLongestOverAll(int **mat, int N){
	/*Write your code here. 
	*Don't write main().
	*Don't take input, it is passed as function argument.
	*Don't print output.
	*Taking input and printing output is handled automatically.
	*/ 
	int longest_path = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int temp_path = 1;
			int path_fail = false;
			int cur_val  = mat[i][j];
			int pi = i;
			int pj = j;
			while(!path_fail)
			{
				//up
				if(pi > 0)
				{
					if(mat[pi-1][pj] == cur_val+1)
					{
						cur_val++;
						 temp_path++;
						 pi =  pi-1;
						 continue;
					 }
				 }
				//right
				if(pj < N-1)
				{
					if(mat[pi][pj+1] == cur_val+1)
					{
						cur_val++;
						temp_path++;
						pj = pj +1;
						continue;
					}
				}
				//down
				if(pi < N-1)
				{
					if(mat[pi+1][pj] == cur_val+1)
					{
						cur_val++;
						temp_path++;
						pi = pi + 1;
						continue;
					}
				}
				//left
				if(pj > 0)
				{
					if(mat[pi][pj-1] == cur_val +1)
					{
						cur_val++;
						temp_path++;
						pj= pj -1;
						continue;
					}
				}
				path_fail = true;
			}
			if(temp_path > longest_path)
			{
				longest_path = temp_path;
				//cout<<"longest path found at("<<i<<","<<j<<")"<<endl;
			}
		}
	}
	return longest_path;
}
int main()
{
	int n;
	cin>>n;
	int **mat;
	mat = new int*[n];
	for(int i=0;i<n;i++)
	{
		mat[i] = new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	cout<<finLongestOverAll(mat,n);
	return 0;
}
