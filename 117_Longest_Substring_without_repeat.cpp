/*
You are given a string S that may or may not contain repeating characters.
Your task is to find out the length of the longest substring of this given string that does not contain any repeating characters.
NOTE : You have to return the length.No need of printing it.
Input Format :
String S
Output Format :
Length of required substring
Sample Input :
ibnoffjytr
Sample Output :
5
*/

#include<iostream>
using namespace std;
int* new_hash()
{
	int *ar = new int[256];
	return ar;
}
int longestSubstr(string S) {
	//this is not working  , & don't know why
	int *hash = new_hash();
	int max_len = 0;
	int len = 0;
	int i = 0;
	while(S[i] != '\0')
	{
		if(hash[int(S[i])-65] == 0)
		{
			hash[int(S[i])-65] = 1;
			len++;
		}
		else
		{
			hash = new_hash();
			if(max_len < len)
			{
				max_len = len;
			}
			len = 0;
			i--;
		}
		i++;
	}	
	return max_len;
}

int longestSubstr(string str) {
	int n = str.size(); 
    int cur_len = 1;
    int max_len = 1;
    int prev_index;
      
    int* visited = new int[sizeof(int) * 256]; 
    for (int i = 0; i < 256; i++) 
        visited[i] = -1; 
    visited[str[0]] = 0; 
    for (int i = 1; i < n; i++) { 
        prev_index = visited[str[i]]; 
        if (prev_index == -1 || i - cur_len > prev_index) 
            cur_len++; 
        else { 
            if (cur_len > max_len) 
                max_len = cur_len; 
  
            cur_len = i - prev_index; 
        } 
        visited[str[i]] = i; 
    }  
    if (cur_len > max_len) 
        max_len = cur_len; 
  
    free(visited);
    return max_len; 
}

int main()
{
	string s;
	cin>>s;
	cout<<longestSubstr(s);
	return 0;
}
//AASSbBACDERFF
