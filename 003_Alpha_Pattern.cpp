/*
Print the following pattern for the given N number of rows.

Pattern for N = 3
 A
 BB
 CCC

Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines

*/
#include<iostream>
using namespace std;


int main(){
    
    int n;
    cin>>n;
    char print_able = 'A';
    int i = 0;
    do{
        for(int j=0;j<i+1;j++)
        {
            cout<<print_able;
		}
        cout<<endl;
        print_able++;
        i++;
    }while(i<n);
    
}
