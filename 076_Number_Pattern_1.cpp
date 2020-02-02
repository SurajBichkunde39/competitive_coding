/*
Print the following pattern for the given N number of rows.
Pattern for N = 4
1
11
111
1111
Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Sample Input :
5
Sample Output :
1
11
111
1111
11111

*/
#include<iostream>
using namespace std;

int main() {
	int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            cout<<1;
        }
        cout<<endl;
	}
	return 0;
}
