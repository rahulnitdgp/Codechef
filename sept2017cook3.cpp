//Array may contain repeated numbers

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int power[21];
	for(int i=0;i<21;i++)
	{
		power[i] = pow(2,i);
	}
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int hash[21] = {0};
		int ans = 0;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<21;j++)
			{
				if(arr[i]==power[j] && hash[j]==0)
				{
					hash[j] = 1;
					ans++;
					break;
				}
			}
		}
		ans = k - ans;
		cout<<ans<<endl;
	}
	return 0;
}