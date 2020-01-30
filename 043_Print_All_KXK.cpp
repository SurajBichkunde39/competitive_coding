/*
Given an n x n square matrix, print sum of all sub-squares of size k x k where k is smaller than or equal to n.
See the sample input.

Input format :
Line 1 : Integer K
Line 2 : Integer N
Line 3 : NXN elements of the matrix separated by space

Output Format :
 Print all sums in a specific order

Constraints :
 1 <= K <= 10^2
 1 <= N <= 10^3

Sample Input :
2
3
8 1 3
2 9 3
0 3 5

Sample Output :
20 16 
14 20 

Example : 20 = (8 + 1 + 2 + 9), 16 = (1 + 3 + 9 + 3) and so on.
*/
#include<iostream>
using namespace std; 
void PrintAllSumKxK(int **mat, int n, int k){
	/*Write your code here.
	*Dont write main(). 
	*Dont take input, it is passed as function argument.
	*Print output as specified in question.
	*/
	int i = 0;
	while(i + k != n+1)
	{
		int j = 0;
		while(j+k!=n+1)
		{
			int sum = 0;
			for(int pi = i;pi<i+k;pi++)
			{
				for(int pj=j;pj<j+k;pj++)
				{
					sum+=mat[pi][pj];
				}
			}
			cout<<sum<<" ";
			j++;
		}
		i++;
		cout<<endl;
	}
}

int main()
{
	int n , k;
	cin>>k;
	cin>>n;
	int **arr;
	arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	PrintAllSumKxK(arr , n,k);
	return 0;
}

