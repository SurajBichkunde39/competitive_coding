/*
Given an array of integers and a number x, find the smallest subarray(minimum number of elements) with sum greater than the given value x.
Note: There will be atleast one such subarray. In case of multiple possible subarrays of same size, return the first one.

Input format :
Line 1 : Size of input array
Line 2 : Array elements (separated by space)
Line 3 : x

Note: This problem was asked in initial rounds of Facebook.
Sample Input
6
1 3 5 6 4 3
9
Sample Output
5 6
*/

#include<iostream>
#include<vector>
using namespace std;
vector<int> smallestSubarray1(int sum , vector<int> input)
{
	//simple sliding window solution
	int window = 0;
	int got_sum = 0;
	vector<int> solution;
	for (std::vector<int>::iterator it = input.begin() ; it != input.end(); ++it)
	{
		window++;
		got_sum = got_sum + *it;
		solution.push_back(*it);
		if(got_sum > sum)
			break;
	}
	int initial = 1;	
	window--;
	while(1)
	{
		if(initial+window > int(input.size()))
			break;
		vector<int>::iterator it = input.begin();
		int req_sum=0;
		for(int i=0;i<window;i++)
		{
			req_sum += *(it+initial+i);
		}
		if(req_sum > sum)
		{
			//change the solution array
			solution.erase(solution.begin(),solution.end());
			for(int i=0;i<window;i++)
			{
				solution.push_back(*(it+initial+i));
			}
			initial++;
			window--;
		}
		else
		{
			initial++;
		}
	}
	return solution;
}

vector<int> smallestSubarray(int sum , vector<int> input)
{
	//inplace o(n) approch
	vector<int>::iterator it = input.begin();
	vector<int> solution;
	vector<int> copy_solution;
	int req_sum = 0;
	while(req_sum < sum)
	{
		req_sum += *it;
		solution.push_back(*it);
		copy_solution.push_back(*it);
		it++;
	}
	while(it != input.end())
	{
		if(req_sum > sum)
		{
			solution = copy_solution;
			req_sum -= copy_solution.front();
			copy_solution.erase(copy_solution.begin());
		}
		else
		{
			req_sum -= copy_solution.front();
			copy_solution.erase(copy_solution.begin());
			copy_solution.push_back(*it);
			req_sum += *it;
			it++;
		}
	}
	return solution;
}
int main()
{
	int n;
	cin>>n;
	vector <int> input;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		input.push_back(val);
	}
	int sum ;
	cin>>sum;
	vector<int>subarray = smallestSubarray(sum , input);
	return 0;
}
