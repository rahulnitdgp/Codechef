#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;
	cin>>n>>x;
	int arr[n+1] ,min = INT_MAX, max = INT_MIN;
	int hash[110] = {0};
	int mex, count =0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(min>=arr[i])
			min = arr[i];
		if(max<=arr[i])
			max = arr[i];
		hash[arr[i]] =1;
	}
	if(min >=1)
		mex = 0;
	else
	{
	for(int i=min+1;i<=max+1;i++)
	{
		if(!hash[i])
		{
			mex = i;
			break;
		}
	}
}
if(x<mex)
{
	count = 1;
	cout<<count<<endl;
	return 0;
}
	for(int i=mex;i<x;i++)
	{
		if(!hash[i])
		{
			count++;
		}
	}
	if(hash[x])
		count++;
	cout<<count<<endl;
	return 0;
}