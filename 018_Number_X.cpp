/*
Print the following pattern for the given number of rows.

Pattern for N = 3 (No. of rows = 5, No. of columns = 5)
1   1
 2 2
  3
 2 2
1   1

Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines

Sample Input : 5
Sample Output :
No. of rows = 9, No. of columns = 9

1       1
 2     2
  3   3
   4 4
    5
   4 4
  3   3
 2     2
1       1

*/
#include<iostream>
using namespace std;
void print_line(int p , int n)
{
	int i=1;
	while(i!=p)
	{
		cout<<" ";
		i++;
	}
	cout<<p;
	int count=0;
	while(count != 2*(n-p)-1)
	{
		cout<<" ";
		count++;
	}
	cout<<p;
	cout<<endl;
}
void printPatt(int n)
{
	int i = 1;
	while(i != n)
	{
		print_line(i , n);
		i++;
	}
	int j =0;
	while(j!=n-1)
	{
		cout<<" ";
		j++;
	}
	cout<<n<<endl;
	i = n-1;
	while(i != 0)
	{
		print_line(i,n);
		i--;
	}
}
int main()
{
	int n;
	cin>>n;
	printPatt(n);
	return 0;
}