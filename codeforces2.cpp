#include<bits/stdc++.h>
using namespace std;


void DFS(int current, int visited[], int flag, list<int> adj[], long long* count1, long long* count2)
{
	visited[current] = 1;
	if(flag==1)
		(*count1)++;
	else
		(*count2)++;
	for(list<int>::iterator it=adj[current].begin();it!=adj[current].end();it++)
	{
		if(!visited[*it])
		{
			if(flag==1)
				DFS(*it,visited,2,adj,count1,count2);		
			else
				DFS(*it,visited,1,adj,count1,count2);		
		}
	}
}
int main()
{
	int n,u,v;
	cin>>n;
	list<int> adj[n];
	int i=0;
	while(i<n-1)
	{
		cin>>u>>v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
		i++;
	}
	long long count1 =0;
	long long count2 = 0;
	int visited[n] = {0};
	DFS(0,visited,1,adj,&count1,&count2);
	long long ans = (count2*count1)-(n-1);
	cout<<ans;
	return 0;
}
	
/*
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
long long cnt[2];
void dfs(int node,int pnode,int color)
{
    cnt[color]++;
    for (int i=0;i<v[node].size();i++)
    {
        if (v[node][i]!=pnode)
        dfs(v[node][i],node,!color);
    }
}
int main()
{
    int n;
    //scanf("%d",&n);
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0,0);
    cout<<cnt[0]*cnt[1]-n+1;
    return 0;
}*/