/*
Given an array consisting of positive and negative integers, find the length of the longest continuous subset whose sum is zero.
NOTE: You have to return the length of longest subset .
Input Format :
Line 1 : Contains an integer N i.e. size of array

Line 2 : Contains N elements of the array, separated by spaces
Output Format
 Line 1 : Length of longest continuous subset 
Sample Input :
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output :
5
*/
#include<iostream>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  
  // o(n^2) approch
  int max_len = 0;
  for(int i=0;i<size;i++)
  {
	  int in_max_len=0;
	  int sum = 0;
	  int len = 0;
	  for(int j=i;j<size;j++)
	  {
		  len++;
		  sum += arr[j];
		  if(sum == 0 && len > in_max_len)
				in_max_len = len;
	  }
	  if(in_max_len > max_len)
		max_len = in_max_len;
   }
   return max_len;
}

int main()
{
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<lengthOfLongestSubsetWithZeroSum(ar,n);
	return 0;
}
