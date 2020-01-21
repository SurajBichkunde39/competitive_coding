/*

Print the following pattern for the given number of rows.

Pattern for N = 5
1 
3 2 
4 5 6 
10 9 8 7 
11 12 13 14 15

Input format : N (Total no. of rows)
Output format : Pattern in N lines

*/
#include<iostream>
using namespace std;
void printPatt(int n)
{
	int count = 1;
	bool go_right = true;
	for(int i=1;i<n+1;i++)
	{
		if(go_right){
			for(int j=0;j<i;j++)
			{
				cout<<count<<" ";
				count++;
			}
			go_right = false;
			cout<<endl;
		}
		else{
			count = count + i-1;
			for(int j=0;j<i;j++)
			{
				cout<<count<<" ";
				count--;
			}
			count = count + i+1;
			go_right = true;
			cout<<endl;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	printPatt(n);
	return 0;
}