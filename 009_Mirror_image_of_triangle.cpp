/*
Print the following pattern for the given number of rows.
Pattern for N = 2
  0
 101
21012

Input format : N (Total no. of rows)
Output format : Pattern in N lines

Sample Input :6
Sample Output :
      0
     101
    21012
   3210123
  432101234
 54321012345
6543210123456


*/
#include<iostream>
using namespace std;

void printPatt(int n)
{
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<=n-i-1;j++)
		{
			cout<<" ";
		}
		int count = i;

		while(count !=0)
		{
			cout<<count;
			count--;
		}
		while(count != i+1)
		{
			cout<<count;
			count++;
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