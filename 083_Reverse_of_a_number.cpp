/*
Write a program to generate the reverse of a given number N. Print the corresponding reverse number.
Input format :
Integer N
Constraints:
Time Limit: 1 second
Output format :
Corresponding reverse number
Sample Input 1 :
1234
Sample Output 1 :
4321
Sample Input 2 :
1980
Sample Output 2 :
891
*/
#include<iostream>
using namespace std;

int main() {
	long int n;
    cin>>n;
    while(n%10 == 0)
        n/=10;
    while(n>0)
    {
        cout<<n%10;
        n/=10;
    }
    return 0;
}
