/*

Print the following pattern for the given number of rows.

Pattern for N = 3
333
233
123

Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines

*/
#include<iostream>
using namespace std;


int main(){

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val = n-i;
		int j=0;
		for(;j<i;j++)
		{
			cout<<val;
			val++;
		}
		while(j!=n){
			cout<<n;
			j++;
		}
		cout<<endl; 
	}

}
