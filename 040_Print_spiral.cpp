/*
Given an N*M 2D array, print it in spiral form. 
That is, first you need to print the 1st row, then last column, then last row and then first column and so on.
Print every element only once.

Input format :
Line 1 : N and M, No. of rows & No. of columns (separated by space) followed by N*M  elements in row wise fashion.

Sample Input :
 4 4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

Sample Output :
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
*/
#include<iostream>
using namespace std;
void spiralPrint(int input[][1000], int row, int col){
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/
	//cout<<"In the function"<<endl;
	int top = 0;
	int bottom = row-1;
	int left = 0;
	int right = col-1;
	int dir = 0;
	//0 -> left to right
	//1 -> top to bottom
	//2 -> right to left
	//3 -> bottom to up
	while(top <= bottom && left<=right)
	{
		//cout<<"value of dir"<<dir<<endl;
		switch(dir)
		{
			case (0):
				for(int i=left;i<=right;i++)
					cout<<input[top][i]<<" ";
				top++;
				break;
			case (1):
				for(int i = top;i<=bottom;i++)
					cout<<input[i][right]<<" ";
				right--;
				break;
			case (2):
				for(int i = right;i>=left;i--)
					cout<<input[bottom][i]<<" ";
				bottom--;
				break;
			case (3):
				for(int i=bottom;i>=top;i--)
					cout<<input[i][left]<<" ";
				left++;
				break;
			default:
				break;
		}
		dir = (dir+1)%4;
	}
}
int main()
{
	int n , m;
	cin>>n>>m;
	int arr[n][1000];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	spiralPrint(arr,n,m);
	return 0;
}
