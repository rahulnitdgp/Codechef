//http://www.spoj.com/problems/MST/
#include<bits/stdc++.h>
using namespace std;
//int parent[100000];
struct graph{

	int i,j,k;
};
bool comp(struct graph a, struct graph b)
{
	return (a.k < b.k);
}
int find(int a, int parent[])
{
	while(parent[a]!=a)
	{
		find(parent[a],parent);
	}
	return(a);
}
void unionn(struct graph b[], int a, int parent[])
{
	int xset = find(b[a].i , parent);
	int yset = find(b[a].j , parent);
	parent[xset] = yset;
}
int main()
{
	int n,m;
	long minw=0;
	cin>>n>>m;
	struct graph g[m+2];
	int parent[n+2];
	for(int w=1;w<=n;w++)
		parent[w]=w;
	int w = 1;
	while(w<=m)
	{
		cin>>g[w].i>>g[w].j>>g[w].k;
		w++;
	}
	w=1;
	sort(g+1,g+m+1,comp);
	cout<<"hiiiiii";
	/*while(w<=m)
	{
		cout<<g[w].i<<" "<<g[w].j<<" "<<g[w].k<<endl;
		w++;
	}*/
	w=1;
	//cout<<"hello";
	while(w<=m)
	{
		//cout<<"hello"<<" ";
		if(find(g[w].i , parent) != find(g[w].j , parent) )
		{
			minw = minw + g[w].k;
			cout<<minw<<" ";
			unionn(g,w,parent);
		}
		w++;
	}
	cout<<minw<<endl;
	return 0;
}