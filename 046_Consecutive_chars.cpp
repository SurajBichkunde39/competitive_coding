/*
Given a matrix of characters. Find length of the longest path from a given character(a list of such characters will be given), 
such that all characters in the path are consecutive to each other, i.e., every character in path is next to previous in alphabetical order. 
It is allowed to move in all 8 directions from a cell.
See the sample input.

Input format :
Line 1 : Number of rows M and cols N in the matrix
Line 2 to M + 1 : A string of N individual characters (without spaces)
Line M + 2 : Enter the starting characters list (without spaces)

Output Format :
 Length of longest paths from each letter in separate lines

Constraints :
 1 <= M <= 10^3
 1 <= N <= 10^3

Sample Input :
4 5
abcde
udjfi
mtgna
kunyq
afm

Sample Output :
7
2
1

Explanation :
Length for 'a' = 7
Length for 'f' = 2
Length for 'm' = 1


*/
#include<iostream>
#include<stack>
using namespace std;
struct state{
	int r,c,l;
	char v;
};
int get_len(char** arr , char letter , int i , int j , int row , int col)
{
	int cur_len = 1;
	int prev_len = 1;
	stack<state*> branch;
	int dir = 0;
	while(1)
	{
		//cout<<"GOING FROM :"<<letter<<" VALUE AT ROW COL:"<<arr[i][j]<<" I=>"<<i<<" J=>"<<j<<" SEARCHING FOR:"<<char(letter+1)<<endl;
		bool updated = false;
		int temp = cur_len;
		letter++;
		//upleft
		if(i > 0 && j > 0)
		{
			if(arr[i-1][j-1] == letter)
			{
				updated = true;
				cur_len++;
				dir = 1;
			}
		}	
		//up
		if(i > 0)
		{
			if(arr[i-1][j] == letter)
			{
				if(!updated)
				{
					updated = true;
					cur_len++;
					dir = 2;
				}
				else
				{
					state* newstate = new state();
					newstate->r = i-1;
					newstate->c = j;
					newstate->v = letter;
					newstate->l = temp;
					branch.push(newstate);
				}
			}
		}
		//upright
		if(i>0 && j<col-1)
		{
			if(arr[i-1][j+1] == letter)
			{
				if(!updated)
				{
					updated = true;
					cur_len++;
					dir = 3;
				}
				else
				{
					state* newstate = new state();
					newstate->r = i-1;
					newstate->c = j+1;
					newstate->l = temp;
					newstate->v = letter;
					branch.push(newstate);
				}
			}
		}			
		//right
		if(j<col-1)
		{
			if(arr[i][j+1] == letter)
			{
				if(!updated)
				{
					updated = true;
					cur_len++;
					dir = 4;
				}
				else
				{
					state* newstate = new state();
					newstate->r = i;
					newstate->c = j+1;
					newstate->l = temp;
					newstate->v = letter;
					branch.push(newstate);
				}
			}
		}
		//bottomright
		if(i<row-1 && j<col-1)
		{
			if(arr[i+1][j+1] == letter)
			{
				if(!updated)
				{
					updated = true;
					cur_len++;
					dir = 5;
				}
				else
				{
					state* newstate = new state();
					newstate->r = i+1;
					newstate->c = j+1;
					newstate->l = temp;
					newstate->v = letter;
					branch.push(newstate);
				}
			}
		}
		//bottom
		if(i < row-1)
		{
			if(arr[i+1][j] == letter)
			{
				if(!updated)
				{
					updated = true;
					cur_len++;
					dir = 6;
				}
				else
				{
					state* newstate = new state();
					newstate->r = i+1;
					newstate->c = j;
					newstate->l = temp;
					newstate->v = letter;
					branch.push(newstate);
				}
			}
		}
		//bottomleft
		if(i<row-1 && j>0)
		{
			//cout<<"I am here"<<endl;
			if(arr[i+1][j-1] == letter)
			{
				if(!updated)
				{
					updated = true;
					cur_len++;
					dir = 7;
				}
				else
				{
					state* newstate = new state();
					newstate->r = i+1;
					newstate->c = j-1;
					newstate->l = temp;
					newstate->v = letter;
					branch.push(newstate);
				}
			}
		}
		//left
		if(i>0 && j>0)
		{
			if(arr[i][j-1] == letter)
			{
				if(!updated)
				{
					updated = true;
					cur_len++;
					dir = 8;
				}
				else
				{
					state* newstate = new state();
					newstate->r = i;
					newstate->c = j-1;
					newstate->l = temp;
					newstate->v = letter;
					branch.push(newstate);
				}
			}
		}
		if(!updated)
		{
			if(branch.empty())
				break;
			else
			{
				if(prev_len < cur_len)
				{
					prev_len = cur_len;
				}
				state* br_top = branch.top();
				i = br_top->r;
				j = br_top->c;
				letter = br_top->v;
				cur_len = br_top->l;
				branch.pop();
			}
		}
		else
		{
			switch(dir)
			{
				case 1:
					i--;
					j--;
					break;
				case 2:
					i--;
					break;
				case 3:
					i--;
					j++;
					break;
				case 4:
					j++;
					break;
				case 5:
					i++;
					j++;
					break;
				case 6:
					i++;
					break;
				case 7:
					i++;
					j--;
					break;
				case 8:
					j--;
					break;
				default:
					break;
			}
		}
	}
	return cur_len > prev_len ? cur_len : prev_len;
}
void LongestLetterChain(char **arr , int row , int col , string letters)
{
	int k = 0;
	while(letters[k] != '\0')
	{
		int cur_len = 0;
		int find_len = 0;
		for(int i = 0; i<row ; i++)
		{
			for(int j=0;j<col ; j++)
			{
				if(arr[i][j] == letters[k])
				{
					find_len = get_len(arr , letters[k] , i , j , row , col );
					if (find_len > cur_len)
						cur_len = find_len;
				}
			}
		}
		k++;
		cout<<cur_len<<endl;
	}
}
int main()
{	char **arr;
	int n;
	int m;
	cin>>m>>n;
	arr = new char*[m];
	for(int i=0;i<m;i++)
	{
		arr[i] = new char[n];
	}
	for(int i=0;i<m;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<n;j++)
		{
			arr[i][j] = s[j];
		}
	}
	string letters;
	cin>>letters;
	LongestLetterChain(arr , m , n , letters);
	return 0;
}
/*
4 5
abcde
uxjfi
mtgna
kunyq
a
*/
