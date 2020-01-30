/*
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
See the sample input.

Input format :
Line 1 : size N of the matrix
Line 2 : NXN elements of the matrix separated by space

Output Format :
 Return the max difference 

Constraints :
 1 <= N <= 10^4

Sample Input :
4
9 9 5 1 
4 5 8 0 
7 0 9 7 
5 5 5 6 

Sample Output :
6
*/
#include<iostream>
using namespace std;
int FindMaxDiff(int **mat, int N){
	int max_diff = 0;
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<N-1;j++)
		{
			for(int pi = i+1;pi<N;pi++)
			{
				for(int pj=j+1;pj<N;pj++)
				{
					int diff = mat[pi][pj] - mat[i][j];
					if(max_diff < diff)
						max_diff = diff;
				}
			}
		}
	}
	return max_diff;
}
int main()
{
	int **mat;
	int N;
	cin>>N;
	mat = new int*[N];
	for(int i=0;i<N;i++)
	{
		mat[i] = new int[N];
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>mat[i][j];
		}
	}
	cout<<FindMaxDiff(mat , N);
	return 0;
}
