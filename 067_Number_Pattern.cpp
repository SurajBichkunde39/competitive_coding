/*
Print the following pattern
Pattern for N = 4
       1
     23
   345
 4567
Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input :
5
Sample Output :
          1
        23
      345
    4567
  56789
*/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<n-i;j++)
        {
            cout<<" ";
		}
        int count = i;
        for(int j = 1;j<=i;j++)
        {
            cout<<count;
            count++;
		}
        cout<<endl;
	}
}

