#include<bits/stdc++.h>
using namespace std;

int main()
{
	const int ppw = pow(2,17);
	const int ppw1 = pow(2,18);
	int n,x;
	cin>>n>>x;
	if(n==2)
	{
		if(x==0)
		{
			cout<<"NO";
			return 0;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<0<<" "<<x;
		}
	}
	else if(n==1)
	{
		cout<<"YES"<<endl;
		cout<<x;
	}
	else
	{
		int temp = 0;
		cout<<"YES"<<endl;
		for(int i=1;i<=n-3;i++)
		{
			cout<<i<<" ";
			temp = temp^i;
		}
		if(temp!=x)
		{
			cout<<0<<" "<<ppw<<" "<<(ppw^temp^x);
		}
		else
		{
			cout<<ppw<<" "<<ppw1<<" "<<(ppw^ppw1);
		}
	}
	return 0;
}