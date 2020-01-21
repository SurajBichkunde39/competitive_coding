/*
Print the following pattern for the given number of rows.
Assume, N is always odd.

Pattern for N = 7
   *
  ***
 *****
*******
 *****
  ***
   *

Input format :
N (Total no. of rows and can only be odd)
Output format :
Pattern in N lines

Sample Input : 5
Sample Output :
  *
 ***
*****
 ***
  *


*/
#include<iostream>
using namespace std;
void printPatt(int n)
{
	int i = 1;
	int spaces = n/2;
	while(i<=n)
	{
		for(int j=0;j<spaces ; j++)
		{
			cout<<" ";
		}
		for(int j=0;j<i;j++)
		{
			cout<<"*";
		}
		spaces--;
		cout<<endl;
		i+=2;
	}
	i=n-2;
	spaces = 1;
	while(i>0)
	{
		for(int j=0;j<spaces;j++)
		{
			cout<<" ";
		}
		for(int j=0;j<i;j++)
		{
			cout<<"*";
		}
		cout<<endl;
		spaces++;
		i-=2;
	}
}
int main()
{
	int n;
	cin>>n;
	printPatt(n);
	return 0;
}