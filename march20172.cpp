#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long arr[n+1],hash[n+1];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		for(int i=0;i<n-1;i++)
		{
			if(arr[i]==arr[i+1])
			{
				cout<<arr[i]<<endl;
				break;
			}
		}
		if(abs(arr[0] - arr[1])>1)
			cout<<arr[0]<<endl;
		else if(abs(arr[n-1]-arr[n-2])>1)
			cout<<arr[n-1]<<endl;
	}
	return 0;
}