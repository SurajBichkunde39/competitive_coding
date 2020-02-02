/*
Print the following pattern for the given N number of rows.
Pattern for N = 4
1
11
202
3003
Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Sample Input :
5
Sample Output :
1
11
202
3003
40004
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
        cout<<count-1;
        for(int j = 1;j<count-1;j++)
            cout<<0;
        cout<<count-1<<endl;
        count++;
    }
    return 0;
}
