/*

Given an array of length N, which contains single digit elements at every index. You need to find and return the sum of all elements of the array. But the final sum should also be single digit.
In order to keep the output single digit - you need to keep adding the output number digits till single digit is left.
Input Format :

Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
Single digit sum

Constraints :
1 <= N <= 10^6

Sample Input 1 :
3
9 9 9

Sample Output 1 :
9

Sample Output Explanation :
9 + 9 + 9 = 27
2 + 7 = 9
Hence, ans is 9.

Sample Input 2 :
5
1 7 8 5 9
Sample Output 1 :
3

*/
int dig_sum(int a)
{
    int sum = 0;
    while(a != 0)
    {
        sum+=(a%10);
        a/=10; 
	}
	return sum;
}
int sum(int *arr,int size)
{
    int sum = 0;
    for(int i=0;i<size;i++)
        sum+=arr[i];
    while(sum >10)
        sum = dig_sum(sum);
    
    return sum;
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
	cout<<sum(arr,n);
	return 0;
}