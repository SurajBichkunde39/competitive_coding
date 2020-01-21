/*

Given an array, update each element of the array by the value obtained by dividing the element by 4 (take only integer part). If the value obtained by dividing element by 4 comes out to be 0, then update element with value -1.
Note : Do not return or print array and make changes in same array.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
N elements of array, separated by space

Constraints :
1 <= N <= 10^6

Sample Input :
2 
3 8

Sample Output :
-1 2


*/
#include<iostream>
using namespace std;
void change(int *arr,int l)
{
for(int i=0;i<l;i++)
{
    if(arr[i]/4 == 0)
        arr[i] = -1;
    else
        arr[i] = arr[i]/4;
}
}

int main()
{
	int n;
	int *arr;
	cin>>n;
	arr = new int[arr];
	for(int i=0i<n;i++)
	{
		cin>>arr[i];
	}
	change(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}