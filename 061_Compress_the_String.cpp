/*
Write a program to do basic string compression. 
For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
For e.g. if a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".
Note : Consecutive count of every character in input string is less than equal to 9.

Input Format :
Input string S

Output Format :
Compressed string 

Sample Input:
aaabbccdsa

Sample Output:
a3b2c2dsa

*/
#include<iostream>
using namespace std;
void shift(char input[] , int star_index , int shift_count)
{
	int i = star_index;
	while(input[i+shift_count] != '\0')
	{
		input[i] = input[i+shift_count];
		i++;
	}
	input[i] = '\0';
}
void stringCompression(char input[]) {
    int i = 0;
    while(input[i] != '\0')
    {
		char given_char = input[i];
		int count = 1;
		while(input[i+count] == given_char)
		{
			count++;
		}
		if(count >= 2)
		{
			input[i+1] = char(48+count);
			i++;
			shift(input ,i+1,count-2);
		}
		i++;
	}
}

int main()
{
	char input[1000];
	cin>>input;
	stringCompression(input);
	return 0;
}
