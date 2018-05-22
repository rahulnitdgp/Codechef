//If N is the at the center of our array, and the entire array is in increasing order with equal increments, 
//it becomes the mean of medians of all sub-arrays of a particular length. eg. for subarrays of length 1,
//since N is the center element, it becomes the mean. Same for all other lengths of sub-arrays. 
//This can then be extended to say that N becomes the mean of medians for all lengths of sub-arrays.

#include<bits/stdc++.h>
using namespace std;
//One Form of Solution
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int start,end;
		if(n%2==0)
		{
			start = n - (n-1)/2;
			end = n + (n+1)/2;
			for(int i = start; i<=end; i++)
				cout<<i<<" ";
		}
		else
		{
			start = n - (n-1)/2;
			end = n + (n-1)/2;
			for(int i = start ; i<=end; i++)
				cout<<i<<" ";	
		}
		cout<<endl;
	}
	return 0;
}