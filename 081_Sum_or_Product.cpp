/*
Write a program that asks the user for a number N and a choice C. And then give him the possibility to choose between computing the sum and computing the product of 1 ,..., N.
If user enters C is equal to -
 1 : Print sum of 1 to N numbers
 2 : Print product of 1 to N numbers
 Any other number : print -1
Input format :
Line 1 : Integer N
Line 2 : Choice C (1 or 2)
Output Format :
 Sum or product according to user's choice
Sample Input 1 :
10
1
Sample Output 1 :
55
Sample Input 2 :
10
2
Sample Output 2 :
3628800
Sample Input 3 :
10
4
Sample Output 3 :
-1
*/
#include<iostream>
using namespace std;

int main() {
	int n;
    int choice;
    cin>>n;
    cin>>choice;
    int sum = 0;
    int product = 1;
    switch(choice)
    {
        case 1:
            
            for(int i=0;i<=n;i++)
                sum += i;
            cout<<sum<<endl;
            break;
        case 2:
            
            for(int i = 1;i<=n;i++)
                product *= i;
           	cout<<product;
            break;
        default:
            cout<<-1<<endl;
            break;
	}
	
}
