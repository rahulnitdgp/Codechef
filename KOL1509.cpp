#include<bits/stdc++.h>
using namespace std;
struct Point
{
	int x,y;
}points[1000000];
int main()
{
	int t,n,a[100000],maxx[100000],mini[100000];
	cin>>t;
	while(t--)
	{
		long area = 0;
		cin>>n;
		if(n<3)
		{
			area = 0;
			cout<<area<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			maxx[i] = mini[i] = 0;
		}
		maxx[0] = a[0];
		mini[0] = a[0];
		for(int i=1;i<n-1;i++)
		{
			maxx[i] = maxx[i-1];
			if(a[i]>maxx[i-1])
				maxx[i] = a[i];
			mini[i] = mini[i-1];
			if(a[i]<mini[i-1])
				mini[i] = a[i];
		}
		int k=0,j=1;
		for(int i=n-1;i>=1;i--)
		{
			points[k].x = maxx[i-1];
			points[k++].y = a[i];
		}
		for(int i=2;i<n;i++)
		{
			points[k].x = mini[i-1];
			points[k++].y = a[i];
		}
		for(int i=0;i<k-1;i++)
		{
			area = area + ((points[i].x)*(points[i+1].y)) - ((points[i+1].x)*(points[i].y));
			cout<<"("<<points[i].x<<","<<points[i].y<<")"<<endl;
		}
		cout<<area<<endl;
		cout<<"("<<points[k-1].x<<","<<points[k-1].y<<")"<<endl;
		area = area + ((points[k-1].x)*(points[0].y)) - ((points[0].x)*(points[k-1].y));
		cout<<abs(area)<<endl;
	}
	return 0;
}