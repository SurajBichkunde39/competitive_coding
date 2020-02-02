
/*
Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
N varies from 1 to 1000.
Input format :
Integer x
Output format :
Terms of series (separated by space)
Sample Input 1 :
10
Sample Output 1 :
5 11 14 17 23 26 29 35 38 41
Sample Input 2 :
4
Sample Output 2 :
5 11 14 17
*/

#include<iostream>
using namespace std;

int main() {
	int n;
    cin>>n;
    int term_count = 0;
    int i = 1;
    while(term_count != n)
    {
        int val = 3*i + 2;
        if(val %4 != 0)
        {
            cout<<val<<" ";
            term_count++;
        }
        i++;
    }
	return 0;
}
