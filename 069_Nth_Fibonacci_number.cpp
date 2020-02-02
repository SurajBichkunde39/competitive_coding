/*
Nth term of fibonacci series F(n) is calculated using following formula -
    F(n) = F(n-1) + F(n-2), 
Provided N you have to find out the Nth Fibonacci Number. Also F(1) = F(2) = 1.
Input Format :
Integer n
Constraints:
Time Limit: 1 second
Output Format :
Nth Fibonacci term i.e. F(n)
Sample Input :
4
Sample Output :
3 

*/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    if(n==0)
        cout<<0;
    else if(n==1)
        cout<<1;
    else if(n==2)
        cout<<1;
    else
    {
        int first = 1;
        int sec = 1;
        for(int i=0;i<n-2;i++)
        {
            int temp = sec;
            sec = first+sec;
            first = temp;
		}
        cout<<sec;
	}
}
