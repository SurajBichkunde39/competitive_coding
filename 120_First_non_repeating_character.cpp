/*
In a given string, find the first non-repeating character .You are given a string, that can contain repeating characters. 
Your task is to return the first character in this string that does not repeat. i.e., occurs exactly once. 
The string will contain characters only from English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). 
If there is no non-repeating character print the first character of string.

Input Format :
Line 1 : A String , as mentioned above.

Output Format :
First non-repeating character
Sample Input 1 :
aDcadhc
Sample Output 1:
D

Sample Input 2 :
gdhIgHada
Sample Output 2 :
h

*/
#include<iostream>
#include<cstring>
using namespace std;
char nonRepeatingCharacter(string str){
	int *hash = new int[256];
	int i=0;
	while(str[i] != '\0')
	{
		if(hash[int(str[i])] == 0)
		{
			//cout<<str[i]<<endl;
			hash[int(str[i])] = 1;
			int j = i+1;
			while(str[j] != '\0')
			{
				if(str[j] == str[i])
					break;
				j++;
			}
			if(str[j] == '\0')
			{
				//cout<<"Returning from in "<<endl;
				return str[i];
			}
		}
		i++;
	}
	//cout<<"returning from very end"<<endl;
	return str[0];
}
int main()
{
	string str;
	cin>>str;
	cout<<nonRepeatingCharacter(str);
	return 0;
}
