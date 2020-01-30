/*
Given a matrix where every cell has some number of coins. Count number of ways to reach bottom right from top left with exactly k coins. 
We can move to (i+1, j) and (i, j+1) from a cell (i, j).
Note: Answer should be mod(10^9+7)
See the sample input.

Input format :
Line 1 : Number of rows M and cols N in the matrix
Line 2 to M + 1 : MXN elements of the matrix
Line M + 2 : Coins to spare K

Output Format :
 (Return the number of ways)%(10^9 + 7)

Constraints :
 1 <= M <= 10^3
 1 <= N <= 10^3
 1 <= K <= 10^3

Sample Input :
3 3
5 2 5 
3 3 1 
3 5 1 
14

Sample Output :
1

*/
#include<iostream>
#include<stack>
using namespace std;
struct state{
	int r,c,remaining_coin;
};
int FindPathsWithKCoins(int **mat, int Rows, int Cols, int k)
{
	cout<<endl;
	stack<state*> branches;
	bool find_path = true;
	int num_path = 0;
	int r = 0;
	int c = 0;
	int remaining_coin = k - mat[0][0];
	while(find_path)
	{
		if(r == Rows-1 && c == Cols-1)
		{
			if(remaining_coin == 0)
			{
				num_path++;
			}
			if(branches.empty())
				break;
			else
			{
				state* last_state;
				last_state = branches.top();
				r = last_state->r;
				c = last_state->c;
				remaining_coin = last_state->remaining_coin;
				branches.pop();
			}
		}
		bool step_taken = false;
		int dir = 0;
		int temp = remaining_coin;
		//go_next col
		if(c < Cols-1)
		{
			if(temp >= mat[r][c+1])
			{
				step_taken = true;
				dir = 1;
				remaining_coin -= mat[r][c+1];
			}
		}
		//try next row
		if(r < Rows-1)
		{
			if(temp >= mat[r+1][c])
			{
				if(step_taken)
				{
					state* newstate = new state();
					newstate->r = r+1;
					newstate->c = c;
					newstate->remaining_coin = temp - mat[r+1][c];
					branches.push(newstate);
				}
				else
				{
					dir = 2;
					step_taken = true;
					remaining_coin -= mat[r+1][c];
				}
			}
		}
		//if no ware to go
		if(!step_taken)
		{
			if(branches.empty())
				break;
			else
			{
				state* last_state;
				last_state = branches.top();
				r = last_state->r;
				c = last_state->c;
				remaining_coin = last_state->remaining_coin;
				branches.pop();
			}
		}
		else
		{
			switch(dir)
			{
				case 1:
					c++;
					break;
				case 2:
					r++;
					break;
				default:
					break;
			}
		}
	}
	return num_path;
}
				
int main()
{
	int rows;
	int cols;
	cin>>rows>>cols;
	int **mat;
	mat = new int*[rows];
	for(int i=0;i<rows;i++)
	{
		mat[i] = new int[cols];
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cin>>mat[i][j];
		}
	}
	int k;
	cin>>k;
	cout<<FindPathsWithKCoins(mat,rows,cols,k);
	return 0;
}
