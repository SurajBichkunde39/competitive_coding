/*
Print the following pattern for the given number of rows.

Pattern for N = 4
****
***
**
*

Input format : N (Total no. of rows)
Output format : Pattern in N lines

*/
#include<iostream>
using namespace std;
void printPatt(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
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