/*
Print the following pattern for the given number of rows.

Pattern for N = 3
*   *
 * *
* * *
 * *
*   *

Input format : N (Total no. of rows)
Output format : Pattern in N lines

Sample Input : 5
Sample Output :
*       *
 *     *
* *   * *
 * * * *
* * * * *
 * * * *
* *   * *
 *     *
*       *

*/
#include<iostream>
using namespace std;
void printPatt(int n)
{
	int max = 2*n-1;
	char ar[max][max];
	
	for(int i=0;i<2*n-1;i++)
	{
		for(int j=0;j<2*n-1;j++)
		{
			ar[i][j] = ' ';
		}
	}
	int count = n;
	int col = 0;
	while(count !=0)
	{
		for(int i=col;i<max-col;i++)
		{
			ar[i][col] = '*';
			ar[i][max-col-1] = '*';
			i++;
		}
		col++;
		count--;
	}
	
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<max;j++)
		{
			cout<<ar[i][j];
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