/*
You are given a (9X9) square integer matrix, that contains values between 0-9.
This matrix represents a sudoku. Check if sudoku is valid or not.
- The sudoku can be completely filled or partially filled.
- An entry 0 indicates that the corresponding cell is empty.
- Your task is to find out whether this sudoku is valid or not.
- Standard sudoku rules are to be enforced to check whether a sudoku is valid/invalid.
    1. No value should be repeating in a given row.
    2. No value should be repeating in a given column.
    3. No value should be repeating in each of the 9 (3X3) square grids.
- Return a boolean response.
Input Format :
 Line 1 : contains the corresponding ith and jth entries of the 2D matrix
Sample Output :
true or false
Sample Input :
6   0   8   2   5   1   7   3   0  
2   3   7   6   9   4   5   1   0  
1   5   9   3   8   7   6   4   0
3   7   1   9   6   0   4   8   5
5   9   0   1   4   8   3   6   7  
8   6   4   7   0   5   9   2   0
7   8   5   4   0   3   1   0   6
4   2   6   5   1   9   8   7   3
9   1   3   8   7   6   2   5   4 
Sample Output :
true
*/

#include<iostream>
using namespace std;
void clear_hash(int *hash)
{
	for(int i=0;i<9;i++)
	{
		hash[i] = -1;
	}
}
int checkValid(int** arr, int numRows, int numCols){
	//cout<<"Function called sucessfully"<<endl;
	int* hash = new int[9];
	//for scanning rows
	for(int i=0;i<9;i++)
	{
		clear_hash(hash);
		for(int j=0;j<9;j++)
		{
			if(arr[i][j] != 0 && hash[arr[i][j]-1] != -1)
			{	
				//cout<<arr[i][j]<<" "<<hash[arr[i][j]]<<endl;
				return 1;
			}
			if(arr[i][j] != 0)
				hash[arr[i][j]-1] = 1;
		}
	}
	//cout<<"ALl row complete"<<endl;
	//for scaning columns
	for(int j=0;j<9;j++)
	{
		clear_hash(hash);
		for(int i=0;i<9;i++)
		{
			if(arr[i][j] != 0 && hash[arr[i][j]-1] != -1)
				return 1;
			if(arr[i][j] != 0)
				hash[arr[i][j]-1] = 1;
		}
	}
	//cout<<"all columns complete"<<endl;
	//for 3X3 block format
	for(int i =0;i<9;i+=3)
	{
		for(int j=0;j<9;j+=3)
		{
			clear_hash(hash);
			for(int m=i;m<i+3;m++)
			{
				for(int n=j;n<j+3;n++)
				{
					if(arr[m][n] != 0 && hash[arr[m][n]-1] != -1)
						return 1;
					if(arr[m][n] != 0)
						hash[arr[m][n]-1] = 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int numRows , numCols;
	numRows = 9;
	numCols = 9;
	int **arr;
	arr = new int*[9];
	for(int i=0;i<9;i++)
		arr[i] = new int[9];
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<checkValid(arr,numRows , numCols)<<endl;
	return 0;
}
