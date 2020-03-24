/*
There are N boxes with different number of toys in them, divide maximum number of toys equally among K children. 
You have to select a group of boxes which are in consecutive order.

Input format :
Line 1 : Integer N 
Line 2 : N integers separated be a single space
Line 3 : Integer K

Output Format :
 Integer

Constraints :
 1 <= N <= 10^4
 0 <= Arr[i] <= 10^4
 1 <= K <= 10^4

Sample Input :
5
0 4 1 3 2
3

Sample Output :
2

Explanation :
Sum from arr[2] to arr[4] = 6
Maximum toys  = 6/3 = 2 
*/

#include<iostream>
#include<map>
using namespace std;
int FindMaximumEqualCount(int arr[], int n, int k){
	int sum = 0;
	int max = 0;
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
		if(sum % k == 0)
		{
			if(max < sum/k)
			{
				max = sum/k;
			}
		}
		int part_sum = arr[i];
		for(int j=i+1;j<n;j++)
		{
			part_sum += arr[j];
			if(part_sum % k == 0)
			{
				if (max < part_sum/k)
				{
					max = part_sum/k;
				}
			}
		}
	}
	return max;	
}
int main()
{
	int n;
	cin>>n;
	int *ar = new int[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	int k;
	cin>>k;
	cout<<FindMaximumEqualCount(ar,n,k);
	return 0;
}
