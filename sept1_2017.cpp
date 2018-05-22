#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n , min, min_index;
		cin>>n;
		int ar[n];
		min = INT_MAX;
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			if(ar[i] < min)
				min = ar[i];
		}
		for(int i=0;i<n;i++)
		{
			if(ar[i] == min)
			{
				min_index = i+1;
				break;
			}
		}
		cout<<min_index;
		cout<<endl;
	}
	return 0;
}
		