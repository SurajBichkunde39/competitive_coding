/*
Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns) in which every elements is either X or O. 
The Xs and Os must be filled alternatively, the matrix should have outermost rectangle of Xs, then a rectangle of Os, then a rectangle of Xs, and so on.
See the sample input.

Input format :
Line 1 : Number of rows M and cols N in the matrix
Line 2 : MXN elements of the matrix separated by space 

Output Format :
 Print the matrix

Constraints :
 1 <= M <= 10^3
 1 <= N <= 10^3

Sample Input :
3 3

Sample Output :
XXX
XOX
XXX

*/
#include<iostream>
using namespace std;
void PrintPattern(int m, int n){
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/
	//cout<<"In the function"<<endl;
	int row = m;
	int col = n;
	char input[m][n];
	int top = 0;
	int bottom = row-1;
	int left = 0;
	int right = col-1;
	char fill_char = 'X';
	//0 -> left to right
	//1 -> top to bottom
	//2 -> right to left
	//3 -> bottom to up
	while(top <= bottom && left<=right)
	{
		//cout<<"value of dir"<<dir<<endl;
		for(int i=left;i<=right;i++)
			input[top][i] = fill_char;
		top++;
			
		for(int i = top;i<=bottom;i++)
			input[i][right] = fill_char;
		right--;
				
		for(int i = right;i>=left;i--)
			input[bottom][i] = fill_char;
		bottom--;
				
		for(int i=bottom;i>=top;i--)
			input[i][left] = fill_char;
		left++;
		if(fill_char == 'X')
			fill_char = 'O';
		else
			fill_char = 'X';
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<input[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int n , m;
	cin>>n>>m;
	PrintPattern(n,m);
	return 0;
}

