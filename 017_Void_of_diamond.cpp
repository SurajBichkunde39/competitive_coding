/*
Print the following pattern for the given number of rows.

Pattern for N = 5
*****
** **
*   *
** **
*****

Input format : N (Total no. of rows and N can only be odd)
Output format : Pattern in N lines

Sample Input : 9
Sample Output :
*********
**** ****
***   ***
**     **
*       *
**     **
***   ***
**** ****
*********

*/
#include<iostream>
using namespace std;

void printPatt(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	int spaces = 1;
	int first = n/2;
	while(first != 1)
	{
		for(int i=0;i<first;i++)
		{
			cout<<"*";
		}
		for(int i=0;i<spaces;i++)
		{
			cout<<" ";
		}
		for(int i=0;i<first;i++)
		{
			cout<<"*";
		}
		spaces+=2;
		first--;
		cout<<endl;
	}
	while(first != n/2+1)
	{
		for(int i=0;i<first;i++)
		{
			cout<<"*";
		}
		for(int i=0;i<spaces ; i++)
		{
			cout<<" ";
		}
		for(int i=0 ; i<first;i++)
		{
			cout<<"*";
		}
		cout<<endl;
		first++;
		spaces-=2;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"*";
	}
}


int main()
{
	int n;
	cin>>n;
	printPatt(n);
	return 0;
}