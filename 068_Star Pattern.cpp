/*
Print the following pattern
Pattern for N = 4
    *
   *** 
  *****
 *******
Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input 1 :
3
Sample Output 1 :
   *
  *** 
 *****

*/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
            cout<<" ";
        for(int j=0;j<i;j++)
            cout<<"*";
        cout<<"*";
        for(int j=0;j<i;j++)
            cout<<"*";
       	cout<<endl;
	}
  
}

