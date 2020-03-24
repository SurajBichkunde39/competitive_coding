/*
Find number of elements to be removed to make an array of all distinct elements.
Example:
Ar = {2,1,4,2,1} 
output = 2 (remove 2 and 1).
Input format :
Line 1 : Integer N 
Line 2 : N integers separated be a single space
Output Format :
 Integer
Constraints :
 0 <= N <= 10^4
Sample Input :
5
2 1 4 2 1
Sample Output :
2
*/
#include<iostream>
#include<set>
using namespace std;
int CountExtraElements(int arr[], int n) {
	set<int>uniq;
	for(int i=0;i<n;i++)
		uniq.insert(arr[i]);
	return n-uniq.size();
}
int main()
{
	int n;
	cin>>n;
	int *ar = new int[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	cout<<CountExtraElements(ar,n);
	return 0;
}
