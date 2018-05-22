#include<bits/stdc++.h>
using namespace std
long a[1000000],ans[1000000],st[100000000];
vector<bool>is_prime(1000010,true);
void sieve()
{
	is_prime[0]=is_prime[1] = false;
	for(long i=2;i*i<1000010;i++)
	{
		if(is_prime[i]==true)
		{
			for(long j=i*i;j<1000010;j+=i)
			{
				if(is_prime==true)
					is_prime[j]=false;
			}
		}
	}
}
void seg_tree(long node,long s,long e)
{
	if(s==e)
		st[node]=lpd(a[s]);
	else
	{
		long mid = (s+e)/2;
		seg_tree(2*n + 1,s,mid);
		seg_tree(2*n + 2,mid+1,e);
		st[node] = max(st[2*node + 1],st[2*node + 2]);
	}
}
update(long node,long s,long e,long l,long r)
{
	if (lazy[node] != 0)
    {
        tree[node] += (e-s+1)*lazy[node];
        if (s != e)
        {
            lazy[node*2 + 1]   += lazy[node];
            lazy[node*2 + 2]   += lazy[node];
        }
        lazy[node] = 0;
    }
 
    // out of range
    if (s>e || s>r || e<l)
        return ;
    if (s>=l && e<=r)
    {
        // Add the difference to current node
        tree[node] += (e-s+1)*diff;
 
        // same logic for checking leaf node or not
        if (s != e)
        {
            lazy[node*2 + 1]   += diff;
            lazy[node*2 + 2]   += diff;
        }
        return;
    }
 
    // If not completely in rang, but overlaps, recur for
    // children,
    int mid = (s+e)/2;
    updateRangeUtil(node*2+1, s, mid, l, r);
    updateRangeUtil(node*2+2, mid+1, e, l, r);
 
    // And use the result of children calls to update this
    // node
    tree[node] = tree[node*2+1] + tree[node*2+2];
}
int main()
{
	long t,n,m,l,r;
	int type;
	cin>>t;
	sieve();
	while(t--)
	{
		long k=0;
		cin>>n>>m;
		for(long i=0;i<n;i++)
		{
			cin>>a[i];
		}
		seg_tree(0,0,n-1);
		for(long i=0;i<m;i++)
		{
			cin>>type>>l>>r;
			if(type==1)
			{
				ans[k++] = get(l,r);
			}
			else
			{
				update(0,0,n-1,l,r);
			}
		}
		for(long i=0;i<k;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}