/*
You are given a string s. Your task is to determine, if the given string s contains two non-overlapping substrings "AB" and "BA" 
(the substrings can go in any order). Print "yes" or "no".
The string s contains uppercase Latin letters only.

Input format :
Line 1 : String s

Output format :
yes or no

Constraints :
1 <= n (Length of String s) <= 10^5

Sample Input 1 :
ABA
Sample Output 1 :
no

Sample Input 2 :
BACFAB
Sample Output 2 :
yes

Sample Input 3 :
AXBYBXA
Sample Output 3 :
no

*/
#include<iostream>
using namespace std;
void twoSubstrings( string s)
{
    // Write your code here
    int i = 0;
    bool first = false;
    bool second = false;
    while(s[i+1] != '\0')
    {
		if(s[i] == 'A' && s[i+1] == 'B')
		{
			first = true;
			i+=2;
		}
		else if(s[i] == 'B' && s[i+1] == 'A')
		{
			second = true;
			i+=2;
		}
		i++;
	}
	if(first && second)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}
int main()
{
	string s;
	cin>>s;
	twoSubstrings(s);
	return 0;
}
