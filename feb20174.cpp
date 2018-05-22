#include<bits/stdc++.h>
using namespace std;
long array[1000000],array1[1000000],ind=0,ind_ans=0;
struct node
{
	long maxx, index;
}tree[10000000];
void build_tree(int start,int end,int node)
{
	if(start==end)
	{
		tree[node].maxx = array1[start];
		tree[node].index = start;
	}
	else
	{
		int mid=(start+end)/2;
		build_tree(start,mid,2*node);
		build_tree(mid+1,end,2*node + 1);
		tree[node].maxx = max(tree[2*node].maxx,tree[2*node + 1].maxx);
		if(tree[node].maxx == tree[2*node].maxx)
			tree[node].index = tree[2*node].index;
		else
			tree[node].index = tree[2*node + 1].index;
	}
}
long query_tree(int start,int end,int node,int l,int r)
{
	long p1,p2;
	if(start>r || end<l)
		return 0;
	else if(start>=l && end<=r)
	{
		ind = tree[node].index;
		return(tree[node].maxx);
	}
	else
	{
		int mid = (start+end)/2, ind1, ind2;
		p1 = query_tree(start,mid,2*node,l,r);
		ind1 = ind;
		p2 = query_tree(mid+1,end,2*node + 1,l,r);
		ind2 = ind;
		if(p1>=p2)
			ind_ans = ind1;
		else
			ind_ans = ind2;
		ind = ind_ans;
		return(max(p1,p2));
	}
}
int main()
{
	int n,m,l,r,k,ans=0;
	cin>>n>>m;
	array[0]=array1[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>array[i];
		array1[i] = 0;
		if(i==1)
		{
			array1[i]=1;
			//hash[array1[i]] = array[i];
		}
		else
		{
			if(array[i-1]==array[i])
			{
				array1[i]=array1[i-1]+1;
				//hash[array1[i]] = array[i];
			}
			else
			{
				array1[i] = 1;
				//hash[array1[i]] = array[i];
			}
		}
	}
	build_tree(1,n,1);
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>k;
		ind_ans = ind = 0;
		int mid = l + ((r-l+1)/2);
		ans = query_tree(1,n,1,mid,r);
		if(ans>=k)
		{
			if((ind_ans-l+1)>=k)
			cout<<array[ind_ans]<<endl;
			else cout<<-1<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}