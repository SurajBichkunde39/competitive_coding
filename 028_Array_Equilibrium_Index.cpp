/*
Find and return the equilibrium index of an array. 
Equilibrium index of an array is an index i such that the sum of elements at indices less than i is equal to the sum of elements at indices greater than i.
Element at index i is not included in either part.
If more than one equilibrium index is present, you need to return the first one. And return -1 if no equilibrium index is present.

Input format :
Line 1 : Size of input array
Line 2 : Array elements (separated by space)

Constraints:
Time Limit: 1 second
Size of input array lies in the range: [1, 1000000]

Sample Input :
7
-7 1 5 2 -4 3 0
Sample Output :
3 
*/
#include<iostream>
using namespace std;
int equ_index(int arr[] , int n)
{
	int total_sum = 0;
	for(int i=0;i<n;i++)
	{
		total_sum = total_sum + arr[i];
	}
	int i=0;
	int left_sum = 0;
	int right_sum = total_sum - arr[0];
	while(i<n-1)
	{
		if(left_sum == right_sum)
			return i;
		left_sum = left_sum + arr[i];
		right_sum = right_sum - arr[i+1];
		i++;
	}
	if(left_sum == 0)
		return n-1;
	return -1;

}
int main()
{
	int n;
	cin>>n;
	int *arr;
	arr = new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<equ_index(arr,n);
}
