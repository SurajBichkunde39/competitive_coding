/*
Given a square binary matrix mat[n][n], find k such that all elements in k’th row are 0 and all elements in k’th column are 1.
The value of mat[k][k] can be anything (either 0 or 1). If no such k exists, return -1.
See the sample input.

Input format :
Line 1 : Size N of the matrix
Line 2 : NXN elements of the matrix separated by space

Output Format :
 Return K

Constraints :
 1 <= N <= 10^3

Sample Input :
3
0 1 1 
0 1 0 
1 1 0 

Sample Output :
1

*/
#include<iostream>
using namespace std;
int FindSpecialRow(int **mat, int N){
	/*Write your code here. 
	*Don't write main().
	*Don't take input, it is passed as function argument.
	*Don't print output.
	*Taking input and printing output is handled automatically.
	*/
	for(int i=0;i<N;i++)
	{
		//check ith row
		int row = i;
		int pcol = 0;
		while(pcol != N)
		{
			if(pcol != i)
			{
				if(mat[row][pcol] != 0)
					break;
			}
			pcol++;
		}
		//check ith col
		int  col = i;
		int prow = 0;
		while(prow != N)
		{
			if(prow != i)
			{
				if(mat[prow][col] != 1)
					break;
			}
			prow++;
		}
		if (prow == N && pcol==N)
			return i;
	}
	return -1;
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
	cout<<FindSpecialRow(mat,n);
	return 0;
}
