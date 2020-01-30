/*
Given a MXN matrix where every row is sorted in increasing order. 
Write a function that finds and returns a common element in all rows. If there is no common element, then returns -1.
See the sample input.

Input format :
Line 1 : Number of rows M and cols N in the matrix
Line 2 : MXN elements of the matrix separated by space

Output Format :
 Return the common element

Constraints :
 1 <= M <= 10^3
 1 <= N <= 10^3

Sample Input :
3 4
6 8 9 9 
1 2 2 9 
0 1 9 10 

Sample Output :
9
*/
#include<iostream>
using namespace std;
bool b_search(int **mat , int val , int row , int cols)
{
	int l = 0;
	int r = cols;
	while(l<=r)
	{
		int m = (l+r)/2;
		//cout<<"VALUE OF LEFT: "<<l<<"  VALUE OF RIGHT: "<<r<<"   VALUE OF MID:"<<m<<endl;
		if(mat[row][m] == val)
			return true;
		if(mat[row][m]>val)
			r = m -1;
		else
			l = m+1;
	}
	return false;
}
int FindCommonEleInRows(int **mat, int M, int N){
	for(int i=0;i<N;i++)
	{
		int val = mat[0][i];
		//cout<<"CHECKING FOR :"<<val<<endl;
		int j = 1;
		while(j != M)
		{
			if(!b_search(mat,val,j,N))
			{
				//cout<<"Breaking for row:"<<j<<endl;
				break;
			}
			j++;
		}
		if(j==M)
			return val;
	}
	return -1;	
}
int main()
{
	int **mat;
	int M , N;
	cin>>M>>N;
	mat = new int*[M];
	for(int i=0;i<M;i++)
	{
		mat[i] = new int[N];
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>mat[i][j];
		}
	}
	cout<<FindCommonEleInRows(mat , M , N);
	return 0;
}
