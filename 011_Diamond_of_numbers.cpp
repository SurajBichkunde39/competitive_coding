/*
Print the following pattern for the given number of rows.

Pattern for N = 7
    1
   123
  12345
 1234567
  12345
   123
    1

Input format : N (Total no. of rows)
Output format : Pattern in N lines

Sample Input : 5
Sample Output :
   1
  123
 12345
  123
   1

*/
#include<iostream>
using namespace std;
void printPatt(int n)
{
	if(n%2 == 0)
		n = n+1;
	int shift = n/2+1;
	int i = 1;
	while(i != shift+1)
	{
		for(int j=0;j<shift-i;j++)
		{
			cout<<" ";
		}
		for(int j=1;j<2*i;j++)
		{
			cout<<j;
		}
		cout<<endl;
		i++;
	}
	while(i != n+1)
	{
		for(int j=0;j<(n/2)-(n-i);j++)
		{
			cout<<" ";
		}
		for(int j=1;j<=2*(n-i)+1;j++)
		{
			cout<<j;
		}
		cout<<endl;
		i++;
	}
	
}
int main()
{
	int n;
	cin>>n;
	printPatt(n);
	return 0;
}