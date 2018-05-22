/*Bartite Graph
#include<bits/stdc++.h>
using namespace std;
 
bool isBipartite(vector< vector<bool> > adjMat, int n){
	 vector<int> visited(n, -1);
	 queue<int> q;
	 		visited[0]=1;
	 		q.push(0);
			while(!q.empty()){
				int x = q.front();
			 	q.pop();
			 	for(int i=0; i<n; i++){
			 		if(adjMat[x][i] && visited[i]==-1){
			 			visited[i] = 1-visited[x];
			 			q.push(i);
			 		}
			 		else if(adjMat[x][i] && (visited[x] == visited[i]))
			 			return false;
			 	}
			}
	return true;
}*/
 int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		vector< vector<bool> > adjMat;
		int n, m;
		scanf("%d %d", &n, &m);
		vector<bool> temp (n, true);
		adjMat.assign(n, temp);
 
		for(long int i=0; i<n; i++)
			adjMat[i][i]=false;
 
		for(long int i=0; i<m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			adjMat[a-1][b-1]=false;
			adjMat[b-1][a-1]=false;
		}
 
		if(isBipartite(adjMat, n))
			printf("YES\n");
		else
			printf("NO\n");
 
	}
	return 0;
 
} 
