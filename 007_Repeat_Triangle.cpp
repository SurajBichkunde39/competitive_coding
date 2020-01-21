/*

Print the following pattern for the given number of rows.

Pattern for N = 3
ABCCBA
 ABBA
  AA

Input format : N (Total no. of rows)
Output format : Pattern in N lines
*/
#include<iostream>
using namespace std;
void printPatt(int n)
{
    for(int i=n;i>0;i--)
{
	for(int j=0;j<n-i;j++){
		cout<<" ";
	}
	
	char back_to = 'A';
	int print_able = int('A');
	int count = i;
	while(count!=0){
		cout<<char(print_able);
		print_able++;
		count--;
	}
	print_able--;
	while(print_able != int(back_to-1)){
		cout<<char(print_able);
		print_able--;
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