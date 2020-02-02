/*
Print the following pattern for the given N number of rows.
Pattern for N = 4
1234
123
12
1
Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Sample Input :
5
Sample Output :
12345
1234
123
12
1

*/
#include<iostream>
using namespace std;

int main() {
	int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int j = 1;
        while(j!=n+1-i)
        {
            cout<<j;
            j++;
        }
        cout<<endl;
    }
    return 0;
}
