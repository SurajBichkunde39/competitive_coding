/*
Given an integer N, print all the prime numbers that lies in between 2 to N 
(both inclusive).
Print the prime numbers in different lines.
Input Format :
Integer N
Output Format :
Prime number in different lines
Constraints :
1 <= N <= 100
Sample Input :
9
Sample Output :
2
3
5
7
*/

#include <iostream>
using namespace std;

int main(){
  int n;
	cin>>n;
	cout<<2<<endl;
	for(int i = 3; i<=n;i++)
	{
		int j = 2;
		while(j != i)
		{
			if(i%j == 0)
				break;
			j++;
		}
		if(j == i)
			cout<<i<<endl;
	}
}
