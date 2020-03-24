/*
Find and return length of maximum consecutive sequence present in the array.

Input format :
Line 1 : Integer N 
Line 2 : N integers separated be a single space

Output Format :
 Maximum Length

Constraints :
 0 <= N <= 10^4

Sample Input :
5
33 20 34 30 35
Sample Output :
3

*/

#include<iostream>
#include<algorithm>
using namespace std;
int LengthOfLongestSeq(int arr[], int n){
	 sort(arr,arr+n);
	 int max_len = 0;
	 for(int i=0;i<n;i++)
	 {
		 int cur_len = 1;
		 int cur_val = arr[i];
		 while(cur_val + 1 == arr[i+1])
		 {
			 i++;
			 cur_len++;
			 cur_val = arr[i];
		 }
		 if(cur_len > max_len)
			max_len = cur_len;
	}
	return max_len;
}

int main()
{
	int n;
	cin>>n;
	int *ar = new int[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	cout<<LengthOfLongestSeq(ar,n);
	return 0;
}
