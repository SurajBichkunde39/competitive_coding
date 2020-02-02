/*
Given a binary number as an integer N, convert it into decimal and print.
Input format :
An integer N
Output format :
Corresponding Decimal number (as integer)
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7
*/
#include<iostream>
using namespace std;

int main() {
	int n;
    cin>>n;
    int multiplier = 1;
    int desimal = 0;
    while(n>0)
    {
        desimal += (n%10)*multiplier;
        multiplier *= 2;
        n/=10;
    }
	cout<<desimal<<endl;
    return 0;
}
