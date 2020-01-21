/*
You are given an array and indices of the array represent minutes and data values represent prices of a stock as they were yesterday . 
You need to figure out and return the maximum profit you can make by buying and selling of the stock. You can buy and sell the stock only once.

Constraints :
1 <= N <= 10^6

Input Format :
Line 1 : An integer N i.e. size of the array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
Single integer i.e. Maximum Profit

Sample Input :
 4 
 2 100 150 120
Sample Output :
148
*/
#include<iostream>
using namespace std;
int maxProfit(int *arr,int l)
{
	int max_profit = arr[1] - arr[0];
	int min_ele = arr[0];
	for(int i=1;i<l;i++)
	{
		if(arr[i] - min_ele > max_profit)
			max_profit = arr[i]-min_ele;
		if(arr[i] < min_ele)
			min_ele = arr[i];
	}
	return max_profit;
}
int main()
{
	int n;
	int *arr;
	cin>>n;
	arr = new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<maxProfit(arr,n);
	return 0;
}
