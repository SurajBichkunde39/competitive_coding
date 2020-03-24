/*
Given an integer array A which contains duplicates. Remove duplicates from the array and return a new array without any duplicates.
That is, it should contain only unique elements.
NOTE : Best case time complexity-O(n) where n is the no of elements in the array.
Input Format :
First element is the size(N) of the array followed by N integers which are elements of the array separated by space
Sample Input :
10 105 106 111 114 105 135 138 111 147 114
Sample Output :
105 106 111 114 135 138 147
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> removeDuplicates(vector<int> input){
	set<int>tracker;
	vector<int>::iterator it;
	vector<int>new_vec;
	for(it=input.begin();it!=input.end();it++)
	{
		auto result = tracker.find(*it);
		if(result == tracker.end())
		{
			tracker.insert(*it);
			new_vec.push_back(*it);
		}
	}
	return new_vec;
}
int main()
{
	int n;
	vector<int>input;
	while(true)
	{
		cin>>n;
		if(n==-1)
			break;
		input.push_back(n);
	}
	input = removeDuplicates(input);
	for(auto i:input)
		cout<<i<<" ";
	return 0;
}
