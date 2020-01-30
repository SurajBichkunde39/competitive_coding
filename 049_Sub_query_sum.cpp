/*
Given a matrix of size M x N, there are large number of queries to find submatrix sums. 
Inputs to queries are left top and right bottom indexes of submatrix whose sum is to find out.

See the sample input.
Input format :
Line 1 : Number of rows M and cols N in the matrix
Line 2 to M + 1 : MXN elements of the matrix
Line M + 2 : Number of queries K
Line M + 3 to M + 3 + K : Co-ordinates of left top and right bottom indices of subquery

Output Format :
 Print the sums in separate lines

Constraints :
 1 <= M <= 10^3
 1 <= N <= 10^3
 1 <= K <= 10^3

Sample Input :
3 4
2 3 8 8 
8 4 8 1 
7 6 0 5 
2
0 2 1 3
1 2 1 3

Sample Output :
25
9

*/
#include<iostream>
using namespace std;
void FindSumInMatrix(int **mat, int rows, int cols, int **subq, int q) {
	for(int i=0;i<q;i++)
	{
		int sum = 0;
		for(int pi=subq[i][0];pi<=subq[i][2];pi++)
		{
			for(int pj = subq[i][1] ; pj<=subq[i][3];pj++)
			{
				sum += mat[pi][pj];
			}
		}
		cout<<sum<<endl;
	}
}

int main()
{
	int rows , cols , q;
	int **mat;
	int **subq;
	cin>>rows>>cols;
	mat = new int*[rows];
	for(int i=0;i<rows;i++)
	{
		mat[i] = new int [cols];
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cin>>mat[i][j];
		}
	}
	cin>>q;
	subq = new int*[q];
	for(int i=0;i<q;i++)
	{
		subq[i] = new int[4];
	}
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>subq[i][j];
		}
	}
	FindSumInMatrix(mat, rows , cols,subq,q);
	return 0;
}
