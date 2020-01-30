/*
Given a n*m binary matrix that is, it contains 0s and 1s only, we need to find and return sum of coverage of all zeros of the input matrix. 
Coverage for a particular 0 is defined as, total number of ones around a zero (i.e. in left, right, up and bottom directions).

Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).

Output format :
Line 1 : print row number

Constraints :
1 <= n, m <= 10^4

Sample Input 1 :
2 2 
1 0
0 1
Sample Output 1 :
4
*/
#include<iostream>
using namespace std;
bool validate_index(int i, int j , int n , int m)
{
	if (i>=0 && i<n && j>=0 && j<m)
		return true;
	return false;
}
int coverage(int **arr,int n,int m)
{
	int conv_sum = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] == 0)
			{
				//up
				if(validate_index(i-1,j,n,m)){
					if(arr[i-1][j] == 1)
						conv_sum += 1;
				}
				//right
				if(validate_index(i,j+1,n,m)){
					if(arr[i][j+1] == 1)
						conv_sum += 1;
				}
				//bottom
				if(validate_index(i+1,j,n,m)){
					if(arr[i+1][j] == 1)
						conv_sum += 1;
				}
				//left
				if(validate_index(i,j-1,n,m)){
					if(arr[i][j-1] == 1)
						conv_sum += 1;
				}
			}
		}
	}
	return conv_sum;
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
	cout<<coverage(arr,n,m);
	return 0;
}
