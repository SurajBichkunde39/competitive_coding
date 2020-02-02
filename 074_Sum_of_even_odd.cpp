/*
Write a program to input an integer N and print the sum of all its even digits and sum of all its odd digits separately.
Digits means numbers not the places. That is, if the given integer is "13245", even digits are 2 & 4 and odd digits are 1, 3 & 5.
Input format :
 Integer N
Output format :
Sum_of_Even_Digits Sum_of_Odd_Digits
(Print first even sum and then odd sum separated by space)
Sample Input :
1234
Sample Output :
6 4
*/
#include<iostream>
using namespace std;

int main() {
	long int n;
    cin>>n;
    int even_sum = 0;
    int odd_sum = 0;
    while(n > 0)
    {
        int val;
        val = n % 10;
        if(val % 2 == 0)
            even_sum += val;
        else
            odd_sum += val;
        n/=10;
	}
    cout<<even_sum<<" "<<odd_sum<<endl;
    return 0;
	
}
