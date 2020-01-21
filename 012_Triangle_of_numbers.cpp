/*
Print the following pattern for the given number of rows.
Pattern for N = 3
       1
     232
   34543

Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines

Sample Input : 5
Sample Output :
           1
         232
       34543
     4567654
   567898765
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2*(n-i);j++)
		{
			cout<<" ";
		}
		int middle_number = 2*i-1;
		int j = i;
		while(j!=middle_number)
		{
			cout<<j;
			j++;
		}
		while(middle_number != i-1)
		{
			cout<<middle_number;
			middle_number--;
		}
		cout<<endl;
	}
	return 0;
    
}
