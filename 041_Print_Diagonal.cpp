/*
Given a 2D matrix, print all elements of the given matrix in diagonal order.
See the sample input.

Input format :
Line 1 : Number of rows R and cols C in the matrix
Line 2 : RXC elements of the matrix separated by space

Output Format :
 Print the diagonals

Constraints :
 1 <= R <= 10^3
 1 <= C <= 10^3

Sample Input :
3 4
8 3 0 7 
0 3 1 8 
3 9 8 7 

Sample Output :
8 
0 3 
3 3 0 
9 1 7 
8 8 
7 

*/
#include<iostream>
using namespace std;
void PrintDiagonals(int **arr, int row, int col){
	/*Write your code here.
	*Dont write main(). 
	*Dont take input, it is passed as function argument.
	*Print output as specified in question.
	*/
	int i = 0;
	while(i != row)
	{
		int pi = i;
		int j =0;
		while(j <col && pi >=0)
		{
			cout<<arr[pi][j]<<" ";
			pi--;
			j++;
		}
		cout<<endl;
		i++;
	}
	int j = 1;
	while(j <col)
	{
		int i = row -1;
		int pj = j;
		while(i>=0 && pj<col)
		{
			cout<<arr[i][pj]<<" ";
			i--;
			pj++;
		}
		cout<<endl;
		j++;
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
	PrintDiagonals(arr,n,m);
	return 0;
}
