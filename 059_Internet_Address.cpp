/*
We know that the address of the Internet resource has format :
        <protocol>://<domain>.ru[/<context>]
where,
- <protocol> can equal either "http" (without the quotes) or "ftp" (without the quotes)
- <domain> is a non-empty string, consisting of lowercase English letters,  
- the /<context> part may not be present. If it is present, then <context> is a non-empty string, consisting of lowercase English letters. 

If string isn't present in the address, then the additional character "/" isn't written. 
Thus, the address has either two characters "/" (the ones that go before the domain), or three (an extra one in front of the context).
Given a string s, which contains all lower case characters without any punctuation marks (":", "/", "."), you have to find out and print the internet resource address.
Note : It is guaranteed that the given string contains at most 50 letters and a valid address.

Input format :
Line 1 : String s

Output format :
Internet address in one line

Constraints :
1 <= n (Length of string) <= 50

Sample Input 1 :
httpsunrux
Sample Output 1 :
http://sun.ru/x

Sample Input 2 :
ftphttprururu
Sample Output 2 :
ftp://http.ru/ruru

*/
#include<iostream>
using namespace std;
void internetAddress(string s) 
{
	int i = 0;
	if(s[i] == 'h')
	{
		while(i!=4)
		{
			cout<<s[i];
			i++;
		}
	}
	else
	{
		while(i!=3)
		{
			cout<<s[i];
			i++;
		}
	}
	cout<<"://";
	bool found_ru = false;
	while(!found_ru)
	{
		if(s[i] == 'r' && s[i+1] == 'u')
		{
			cout<<".ru";
			found_ru = true;
			i+=2;
		}
		else
		{
			cout<<s[i];
			i++;
		}
	}
	cout<<"/";
	while(s[i]!='\0')
	{
		cout<<s[i];
		i++;
	}
	
}
int main()
{
	string s;
	cin>>s;
	internetAddress(s);
	return 0;
}
