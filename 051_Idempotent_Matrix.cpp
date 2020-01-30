/*
Given a N * N matrix and the task is to check matrix is idempotent matrix or not.
See the sample input.

Idempotent matrix M follows the following property :
M*M = M

Input format :
Line 1 : Size N of the matrix
Line 2 to N + 1 : NXN elements of the matrix

Output Format :
 true or false

Constraints :
 1 <= N <= 10^3

Sample Input :
3
2 -2 -4
-1 3 4
1 -2 -3

Sample Output :
true

*/
#include<iostream>
using namespace std;
bool CheckIdempotent(int **mat , int N)
{
	for(int i =0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int sum = 0;
			for(int k=0;k<N;k++)
			{
				sum += mat[i][k]*mat[k][j];
			}
			if(sum != mat[i][j])
				return false;
		}
	}
	return true;
}
int main()
{
	int N;
	cin>>N;
	int** mat;
	mat = new int* [N];
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
	cout<<CheckIdempotent(mat,N);
	return 0;
}
