// https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-learning-graph-3/

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int s,value;
};
bool compare(const node &a, const node &b)
{
	return(a.value > b.value);
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<struct node> adj[n+10];
	struct node temp[n+10];
	int val[n+10];
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
	}
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		temp[y].s = y;
		temp[y].value = val[y];
		temp[x].s = x;
		temp[x].value = val[x];
		adj[x].push_back(temp[y]);
		adj[y].push_back(temp[x]);
	}

	for(int i=1;i<=n;i++)
	{
		sort(adj[i].begin(), adj[i].end(), compare);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<adj[i][k-1].s<<endl;
	}
	return 0;
}