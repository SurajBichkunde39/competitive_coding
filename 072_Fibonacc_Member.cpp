/*
Given a number N, figure out if it is a member of fibonacci series or not. Return true if the number is member of fibonacci series else false.
Fibonacci Series is defined by the recurrence
    F(n) = F(n-1) + F(n-2)
Input Format :
Integer N
Output Format :
true or false
Sample Input 1 :
5
Sample Output 1 :
true
Sample Input 2 :
14
Sample Output 2 :
false 
*/
#include<iostream>
using namespace std;
bool checkMember(int n){
    int first = 1;
    int next = 1;
    while(next <= n)
    {
        if(next == n)
            return true;
        int temp = next;
        next = first + next;
        first = temp;
	}
    return false;
}
int main()
{
	int n;
	cin>>n;
	cout<<checkMember(n);
	return 0;
}
