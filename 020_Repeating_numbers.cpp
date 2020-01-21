/*
Print the following pattern for the given number of rows.

Pattern for N = 3
1
23
4567

Input format : N (Total no. of rows)
Output format : Pattern in N lines

Sample Input : 5
Sample Output :
1
23 
4567
89123456
7891234567891234

*/
#include<iostream>
using namespace std;

int pow(int a , int b)
{
	int ret = 1;
	if(b==0)
		return 1;
	else
	{
		for(int i=0;i<b;i++)
		{
			ret = ret * a;
		}
	}
    return ret;
}

void printPatt(int n)
{
int num = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<pow(2,i);j++)
		{
			cout<<num;
			num = num%9;
			num++;
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	printPatt(n);
	return 0;
}