/*
Given 3 Strings, check whether the 3rd string contains all the characters of string 1 and 2 in any order. 
If all the characters are present, print "YES" otherwise print "NO".
There should not be any extra character and any missing character.
The string s contains uppercase Latin letters only.

Input format :
Line 1 : First String
Line 2 : Second String
Line 3 : Third String

Output format :
YES or NO

Constraints :
1 <= n (Length of 1st & 2nd Strings) <= 100

Sample Input 1 :
SANTACLAUS
DEDMOROZ
SANTAMOROZDEDCLAUS
Sample Output 1 :
YES

Sample Input 2 :
PAPAINOEL
JOULUPUKKI
JOULNAPAOILELUPUKKI
Sample Output 2 :
NO

Sample Input 3 :
BABBONATALE
FATHERCHRISTMAS
BABCHRISTMASBONATALLEFATHER
Sample Output 3 :
NO

Sample Output Explanation :
Output 1 : the letters written in the last line can be used to write the names and there won't be any extra letters left.
Output 2 : Letter "P" is missing and there's an extra letter "L"
Output 3 : There's an extra letter "L"

*/
#include<iostream>
using namespace std;
void answer(string s1,string s2,string s)
{
	int arr[26];
	for(int i=0;i<26;i++)
	{
		arr[i]=0;
	}
	int i = 0;
	while(s[i] != '\0')
	{
		arr[int(s[i])-65]++;
		i++;
	}
	i = 0;
	while(s1[i] != '\0')
	{
		int sol = int(s1[i]) - 65;
		if(arr[sol] != 0)
		{
			arr[sol]--;
		}
		else
		{
			cout<<"NO"<<endl;
			return;
		}
		i++;
	}
	i = 0;
	while(s2[i] != '\0')
	{
		int sol = int(s2[i]) - 65;
		if(arr[sol] != 0)
		{
			arr[sol]--;
		}
		else
		{
			cout<<"NO"<<endl;
			return;
		}
		i++;
	}
	i = 0;
	while(i != 26)
	{
		if(arr[i] != 0)
		{
			cout<<"NO"<<endl;
			return;
		}
		i++;
	}
	if(i == 26)
	{
		cout<<"YES"<<endl;
	}
}

int main()
{
	string s1,s2,s;
	cin>>s1;
	cin>>s2;
	cin>>s;
	answer(s1,s2,s);
	return 0;
}
