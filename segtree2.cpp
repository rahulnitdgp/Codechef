#include<bits/stdc++.h>
using namespace std;
int arr[10000000],tree[10000000];
void build_tree(int start,int end,int node)
{
	if(start == end)
	{
		tree[node] = arr[start];
	}
	else
	{
		int mid = (start + end)/2;
		build_tree(start,mid,2*node);
		build_tree(mid+1,end,2*node + 1);
				
	}
}
int main()
{
	int n,l,r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
	}
	int m;
	cin>>m;
	build_tree(1,n,1);
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r;
		update_tree();
	}
	int q,x;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x;
		query_tree()
	}
	return 0;
}