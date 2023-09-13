#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_V 20000

using namespace std;

int V,E;
int parent[MAX_V+1];
vector<int> graph[MAX_V+1];
bool visited[MAX_V+1];

void init(){
	for(int i=0;i<=V;i++)
		graph[i].clear();
	memset(parent,-1,sizeof(parent));
	memset(visited,false,sizeof(visited));
}

bool BFS(int start){
	queue<pair<int, int> > q;
	q.push(make_pair(start,0));

	while(!q.empty()){
		int cur = q.front().first;
		int curParent = q.front().second;
		q.pop();

		if(visited[cur])
			continue;

		parent[cur] = curParent;
		visited[cur] = true;
		for(int next: graph[cur]){
			if(parent[next] == curParent)
				return false;
			if(visited[next] == false){
				q.push(make_pair(next,curParent ^ 1));
			}
		}
	}
	return true;
}

int main(void)
{
	int K;
	scanf("%d",&K);
	
	for(int test_case=0; test_case < K; test_case++){
		scanf("%d %d",&V,&E);

		init();

		for(int i=0;i<E;i++){
			int u,v;
			scanf("%d %d",&u,&v);			

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool isBipartite = true;
		for(int i=1;i<=V && isBipartite;i++){
			if(!visited[i])
				isBipartite = BFS(i);
		}

		if(isBipartite)
			printf("YES\n");
		else
			printf("NO\n");	
	}	

    return 0;
}