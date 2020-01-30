#include<iostream>
using namespace std;
int* readRowsAlternatively(int **input, int row, int col){
	int *ar;
	ar = new int[row*col];
	int count = 0;
	bool right_ro_left = true;
	for(int i=0;i<row;i++)
	{
		if(right_ro_left)
		{
			for(int j=0;j<col;j++)
			{
				ar[count] = input[i][j];
				count++;
			}
		}
		else
		{
			for(int j = col-1;j>=0;j--)
			{
				ar[count] = input[i][j];
				count++;
			}
		}
		right_ro_left = !right_ro_left;
	}
	return ar;
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
	int *ar = readRowsAlternatively(arr,n,m);
	for(int i=0;i<n*m;i++)
	{
		cout<<ar[i]<<" ";
	}
	return 0;
}
