#include<iostream>
using namespace std;
int minSum(int **input, int n)
{
	int first_min = 0;
	int min_val = input[0][0];
	for(int i=1;i<n;i++)
	{
		if(input[0][i] < min_val)
		{
			cout<<"changing minval"<<endl;
			min_val = input[0][i];
			first_min = i;
		}
	}
	int sum = min_val;
	cout<<"adding to sum :"<<min_val<<endl;
	for(int i=1;i<n;i++)
	{
		int start = (first_min+1)%3;
		int next = (start+1)%3;
		int start_val = input[i][start];
		int next_val = input[i][next];
		if(start_val > next_val)
		{
			first_min = next;
			sum = sum + next_val;
			cout<<"adding to sum :"<<next_val<<endl;
		}
		else
		{
			first_min = start;
			sum = sum + start_val;
			cout<<"adding to sum :"<<start_val<<endl;
		}
		
	}
	return sum;
		
}
int main()
{
	int n;
	cin>>n;
	int **arr;
	arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[3];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<"Printing input"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<minSum(arr, n);
	return 0;
}
