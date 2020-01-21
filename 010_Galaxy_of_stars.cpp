/*
Print the following pattern for the given number of rows.

Pattern for N = 7
*
**
***
****
***
**
*

Input format : N (Total no. of rows)
Output format : Pattern in N lines

Sample Input : 5
Sample Output :
 *
 **
 ***
 **
 *

*/
#include<iostream>
using namespace std;
void printPatt(int n)
{
	if(n %2 ==0)
		n++;
	n = (n+1)/2;
	int count = 1;
	while(count != n+1)
	{
		for(int i=0;i<count;i++)
		{
			cout<<"*";
		}
		cout<<endl;
		count++;
	}
	count-=2;
	while(count != 0)
	{
		for(int i=0;i<count;i++)
		{
			cout<<"*";
		}
		cout<<endl;
		count--;
	}

}
int main()
{
	int n;
	cin>>n;
	printPatt(n);
	return 0;
}