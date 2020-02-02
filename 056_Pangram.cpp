/*
A word or a sentence is called a pangram if all the characters of this language appear in it at least once. 
You are given a string s consisting of lowercase and uppercase Latin letters. Check whether this string is a pangram. Print "YES" or "NO".
We say that the string contains a letter of the Latin alphabet, if this letter occurs in the string in either uppercase or in lowercase.

Input format :
Line 1 : n (Number of characters in string)
Line 2 : Input string s

Output format :
YES or NO

Constraints :
1 <= n <= 100

Sample Input 1 :
12
toosmallword
Sample Output 1 :
NO

Sample Input 2 :
35
TheQuickBrownFoxJumpsOverTheLazyDog
Sample Output 2 :
YES

*/
#include<iostream>
using namespace std;
void ans (int n, string S)
{
	if(n < 26)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		int *arr;
		arr = new int[26];
		int i = 0;
		while(S[i] != '\0')
		{
			int sol = -1;
			if(S[i] >= 'A' && S[i] <= 'Z')
			{
				sol = int(S[i]) - 65;
			}
			else
			{
				sol = int(S[i]) - 97;
			}
			arr[sol] = 1;
			i++;
		}
		i = 0;
		while(i!= 26)
		{
			if(arr[i] == 0)
			{
				cout<<"NO"<<endl;
				return;
			}
			i++;
		}
		if(i == 26)
			cout<<"YES"<<endl;
	}
}
int main()
{
	int len;
	string s1;
	cin>>len;
	cin>>s1;
	ans(len,s1);
	return 0;
}
