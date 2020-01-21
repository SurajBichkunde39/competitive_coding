/*
Print the following pattern for the given number of rows.

Pattern for N = 5
 1    2   3    4   5
 11   12  13   14  15
 21   22  23   24  25
 16   17  18   19  20
 6    7    8   9   10

Input format : N (Total no. of rows)
Output format : Pattern in N lines

Sample Input : 4
Sample Output :
 1  2  3  4
 9 10 11 12
13 14 15 16
 5  6  7  8
*/
#include <iostream>
using namespace std;
void printPattern(int n)
{
	int ar[n][n];
	int index_up = 0;
	int index_down = n-1;
	bool up = true;
	int count = 1;
	do{
		if(up){
			for(int i=0;i<n;i++)
			{
				ar[index_up][i] = count;
				count++;
			}
			up = false;
			index_up++;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				ar[index_down][i] = count;
				count++;
			}
			index_down--;
			up = true;
		}
	}while(index_up != index_down);
	for(int i=0;i<n;i++)
	{
		ar[index_down][i] = count;
		count++;
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}
	