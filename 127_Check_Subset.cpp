/*
Given two integer arrays. Check if second array is a subset of first array.
Input format :
Line 1 : Integer N1 
Line 2 : N1 integers separated be a single space
Line 1 : Integer N2 
Line 2 : N2 integers separated be a single space

Output Format :
 Boolean
Constraints :
 0 <= N1 <= 10^4
 0 <= N2 <= 10^4

Sample Input :
15
3 6 5 8 15 1 14 18 7 9 14 9 3 12 8 
4
18 6 9 8

Sample Output :
true
*/
#include<iostream>
using namespace std;
bool CheckSubset(int arr1[], int n1, int arr2[], int n2) {
	int *hash = new int [10000];
	for(int i=0;i<n2;i++)
		hash[arr2[i]] = i+1;
	for(int i=0;i<n1;i++)
	{
		if(hash[arr1[i]] != 0)
		{
			arr2[hash[arr1[i]]-1] = -1;
		}
	}
	for(int i=0;i<n2;i++)
	{
		if(arr2[i] != -1)
			return false;
	}
	return true;
}
int main()
{
	int n1;
	cin>>n1;
	int *ar1 = new int [n1];
	for(int i=0;i<n1;i++)
		cin>>ar1[i];
	int n2;
	cin>>n2;
	int *ar2 = new int [n2];
	for(int i=0;i<n2;i++)
		cin>>ar2[i];
	cout<<CheckSubset(ar1,n1,ar2,n2);
	return 0;
}
