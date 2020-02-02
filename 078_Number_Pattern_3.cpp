/*
Print the following pattern for the given N number of rows.
Pattern for N = 4
1
11
121
1221
Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Sample Input :
5
Sample Output :
1
11
121
1221
12221

*/
#include<iostream>
using namespace std;

int main() {
	int n;
    cin>>n;
    int count = 1;
    if(n>=1)
    {
        cout<<1<<endl;
        count++;
    }
    while(count != n+1)
    {
        cout<<1;
        for(int j = 1;j<count-1;j++)
            cout<<2;
        cout<<1<<endl;
        count++;
    }
    return 0;
	
}
