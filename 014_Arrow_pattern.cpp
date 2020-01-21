/*
Print the following pattern for the given number of rows.
Assume N is always odd.
Note : There is space after every star.

Pattern for N = 7
*
 * *
   * * *
     * * * *
   * * *
 * *
*

Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines

Sample Input : 11
Sample Output :
*
 * *
   * * *
     * * * *
       * * * * *
         * * * * * *
       * * * * *
     * * * *
   * * *
 * *
*
*/
#include<iostream>
using namespace std;


int main(){

	int n;
	cin>>n;
	int middle = (n+1)/2;
	int spaces = 1;
	int i = 2;
	cout<<"*\n";
	while(i != middle+1)
	{
		for(int j=0;j<spaces;j++)
		{
			cout<<" ";
		}
		for(int j=0;j<i;j++)
		{
			cout<<"* ";
		}
		cout<<endl;
		i++;
		spaces +=2;
	}
	middle--;
	spaces -=4;
	while(middle != 0)
	{
		for(int j=0;j<spaces;j++)
		{
			cout<<" ";
		}
		for(int j=0;j<middle;j++)
		{
			cout<<"* ";
		}
		middle--;
		spaces-=2;
		cout<<endl;
	}
	return 0;
}

