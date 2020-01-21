/*

Print the following pattern for the given number of rows.

Pattern for N = 4
1111
000
11
0

Input format : N (Total no. of rows)
Output format : Pattern in N lines

*/
#include<iostream>
using namespace std;

void printPatt(int n)
{
    bool print_able = true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<print_able;
		}
        cout<<endl;
        print_able= !(print_able);
	}
}


int main()
{
	int n;
	cin>>n;
	printPatt(n);
	return 0;
}