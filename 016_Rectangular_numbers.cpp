/*
Print the following pattern for the given number of rows.

Pattern for N = 4
4444444
4333334
4322234
4321234
4322234
4333334  
4444444

Input format : N (Total no. of rows)
Output format : Pattern in N lines

Sample Input : 3
Sample Output :
33333
32223
32123
32223
33333
*/
#include<iostream>
using namespace std;

void printPatt(int n)
{
	int count = n;
	for(int x=0;x<2*n-1;x++)
	{
		bool count_change = false;
		bool phase_change = false;
		int inner_val = n;
		for(int y=0;y<2*n-1;y++)
		{
			if(x==y)
			{
				cout<<count;
				if(x<n-1)
				{
					count--;
					count_change = true;
				}
				else
				{
					count++;
					phase_change = true;
				}
			}
			else if(count_change)
			{
				count++;
				int i=0;
				for(;i<2*(count-1);i++)
				{
					cout<<count;
				}
				count--;
				int sample = count+2;
				i = i+y;
				while(i < 2*n-1)
				{
					cout<<sample;
					sample++;
					i++;
				}
				break;
			}
			else if(phase_change)
			{
				int sample = count;
				while(sample!=n+1)
				{
					cout<<sample;
					sample++;
				}
				break;
			}		
			else{
				if(x<n)
				{
					cout<<n-y;
				}
				else
				{
					if(inner_val != count)
					{
						cout<<inner_val;
						inner_val--;
					}
					else
					{
						cout<<inner_val;
					}
				}
			}
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