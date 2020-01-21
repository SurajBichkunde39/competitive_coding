/*
Find and return sum of all elements in an array which are either divisible by 2 or by 3.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format:
Single integer which is sum of all those numbers which satisfy the specified condition.

Constraints :
(1<= N <=10^5)

Sample Input 1: 4 3 5 6 7
Sample Output 1: 9
*/
#incude<iostream>
using namespace std;
int FindSum(int *arr,int l)
{
    using namespace std;
    cin>>l;
    //arr = new int[n];
    for(int i=0;i<l;i++)
    {
        cin>>arr[i];
	}
    int sum = 0;
    for(int i=0;i<l;i++)
    {
        if(arr[i]%2 == 0)
            sum += arr[i];
        else if(arr[i] %3 ==0)
            sum += arr[i];
    }
    return sum;
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
	cout<<FindSum(arr,n);
	return 0;
} 