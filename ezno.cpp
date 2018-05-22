#include<bits/stdc++.h>
using namespace std;

long long countt[16][100]={0};
void construct(int b, int l, long long curr)
{
    long M = pow(10,9)+7;
	countt[b][l]=(countt[b][l]+1)%M;
	for(int i=0;i<b;i++)
	{
		long long newnumber = curr*b + i;
		if(newnumber % (l+1) == 0)
			construct(b,l+1,newnumber);
	}
}
int main()
{
	int t,b,d,i,j;
	cin>>t;
	while(t--)
	{
		cin>>b>>d;
		for(i=1;i<b;i++)
		{
			construct(b,1,i);
		}
		cout<<countt[b][d]<<endl;
	}
	return 0;
}
