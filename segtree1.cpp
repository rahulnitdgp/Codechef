//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/

#include<bits/stdc++.h>
using namespace std;
struct node1
{
	int odd,even;
}tree[1000000];
void build_tree(int start, int end, int node, int arr[])
{
	if(	start == end )
	{
		if(arr[start]%2==0)
		{
			tree[node].odd = 0;
			tree[node].even = 0;
			tree[node].even = 1;
		}
		else
		{
			tree[node].odd = 0;
			tree[node].even = 0;
			tree[node].odd = 1;
		}
	}
	else
	{
		int mid = (start + end)/2;
		build_tree(start,mid,2*node,arr); 
		build_tree(mid+1,end,2*node + 1,arr);		
		tree[node].odd = 0;
		tree[node].even = 0;
		tree[node].odd = tree[2*node].odd + tree[2*node + 1].odd;
		tree[node].even = tree[2*node].even + tree[2*node + 1].even;
	}
}	
void update_tree(int start,int end,int idx,int val,int node,int arr[])
{
	if(idx<start || idx>end)
		return;
	if(	start == end )
	{
		arr[start]=val;
		if(arr[start]%2==0)
		{
			tree[node].odd = 0;
			tree[node].even = 0;
			tree[node].even = 1;
		}
		else
		{
			tree[node].odd = 0;
			tree[node].even = 0;
			tree[node].odd = 1;
		}
	}
	else
	{
		int mid = (start + end)/2;
		update_tree(start,mid,idx,val,2*node,arr);
		update_tree(mid+1,end,idx,val,2*node + 1,arr);
		tree[node].odd = 0;
		tree[node].even = 0;
		tree[node].odd = tree[2*node].odd + tree[2*node + 1].odd;
		tree[node].even = tree[2*node].even + tree[2*node + 1].even;
	}
}
int query_tree(int start,int end,int l,int r,int node,int arr[],int a)
{
	if(end<l || start>r)
	{
		return 0;
	}
	else if(l<=start && r>=end)
	{
		if(a==1)
			return(tree[node].even);
		else
			return(tree[node].odd);
	}
	else
	{	
		int mid = (start + end)/2;
		int p1 = query_tree(start,mid,l,r,2*node,arr,a);
		int p2 = query_tree(mid+1,end,l,r,2*node + 1,arr,a);
		return(p1+p2);
	}
}
int main()
{
	int n,s,x,y;
	cin>>n;
	int arr[n+2];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int q;
	cin>>q;
	/*for(int i=1;i<=99999;i++)
	{
		tree[i].odd = tree[i].even = 0;
	}*/
	build_tree(1,n,1,arr);
	for(int i=1;i<=q;i++)
	{
		cin>>s>>x>>y;
		if(s==0)
		{
			update_tree(1,n,x,y,1,arr);
		}
		else
		{
			cout<<query_tree(1,n,x,y,1,arr,s)<<endl;
		}
	}
	return 0;
}