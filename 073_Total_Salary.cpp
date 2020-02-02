/*
Write a program to calculate the total salary of a person. The user has to enter the basic salary (an integer) and the grade (an uppercase character), 
and depending upon which the total salary is calculated as -
    totalSalary = basic + hra + da + allow – pf
where :
hra   = 20% of basic
da    = 50% of basic
allow = 1700 if grade = ‘A’
allow = 1500 if grade = ‘B’
allow = 1300 if grade = ‘C' or any other character
pf    = 11% of basic.

Round off the total salary and then print the integral part only.

Input format :
Basic salary & Grade (separated by space)
Output Format :
Total Salary

Sample Input 1 :
10000 A
Sample Output 1 :
17600

Sample Input 2 :
4567 B
Sample Output 2 :
8762

*/
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int sal;
    char grade;
    cin>>sal;
    cin>>grade;
    float total_sal;
    int allow = 0;
    switch(grade)
    {
        case 'A':
            allow = 1700;
            break;
        case 'B':
            allow = 1500;
           	break;
        default:
            allow = 1300;
            break;
    }
    total_sal = sal + 0.2*sal + 0.5*sal + allow - 0.11*sal;
    total_sal = total_sal - int(total_sal) > 0.5 ? int(total_sal + 1) : int(total_sal);
    cout<<total_sal<<endl;
	
}
