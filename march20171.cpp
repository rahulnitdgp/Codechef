#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long sum1=0,sum2=0;
		
		cin>>n;
		int x[n+1], y[n+1];
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			if(i%2==0)
				sum1+=x[i];
			else
				sum2+=x[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>y[i];
			if(i%2==0)
				sum2+=y[i];
			else
				sum1+=y[i];
		}
		cout<<min(sum1,sum2)<<endl;
	}
	return 0;
}