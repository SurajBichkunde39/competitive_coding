/*
Given a decimal number (integer N), convert it into binary and print.
The binary number should be in the form of an integer.
Note : The given input number could be large, so the corresponding binary number can exceed the integer range. So take the answer as long.
Input format :
Integer N
Output format :
Corresponding Binary number (long)
Sample Input 1 :
12
Sample Output 1 :
1100
Sample Input 2 :
7
Sample Output 2 :
111

*/

#include<iostream>
using namespace std;

int main() {
    int bin[32];
	int n;
    cin>>n;
    int i = 0;
    do
    {
        bin[i] = n%2;
        n /=2;
        i++;
    }while(n!=0);
    i--;
    while(i!=-1)
    {
        cout<<bin[i];
        i--;
    }
    return 0;
	
}
