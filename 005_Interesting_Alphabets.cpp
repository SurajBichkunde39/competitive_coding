/*

Print the following pattern for the given number of rows.

Pattern for N = 5
E
DE
CDE
BCDE
ABCDE

Input format : N (Total no. of rows)
Output format : Pattern in N lines
*/
#include<iostream>
using namespace std;
void printPatt(int n)
{
    char print_able = 'A';
	for(int i=0;i<n+1;i++)
	{
		for(int j = n-i;j<n;j++)
		{
			cout<<char(print_able+j);
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