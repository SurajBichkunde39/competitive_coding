/*
Given an unsorted array of numbers, write a function that returns true if complete array consists of consecutive numbers. That means if we sort the array, all the elements are consecutive. Array contains only positive numbers.
Try doing it in O(n), where n is the size of given array.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
true or false

Constraints :
1 <= N <= 10^6

Sample Input 1 :
6
3 7 2 5 4 6
Sample Output 1 :
true

Sample Input 2 :
6
1 9 2 4 0 3
Sample Output 2 :
false

*/

bool containsConsecutiveNumbers(int input[], int len){
	int min = input[0];
	int max = input[0];
	int sum = 0;
	for(int i=0;i<len;i++)
	{
		if(min > input[i])
			min = input[i];
		if(max < input[i])
			max = input[i];
		sum+=input[i];
	}
	int sum_should = 0;
	for(int i=min;i<max+1;i++)
	{
		sum_should += i;
	}
	
	return (sum_should == sum);

}

#include<iostream>
using namespace std;
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
	cout<<containsConsecutiveNumbers(arr,n);
	return 0;
}