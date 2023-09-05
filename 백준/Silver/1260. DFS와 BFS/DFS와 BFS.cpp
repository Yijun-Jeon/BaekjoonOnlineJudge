#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 1000
#define MAX_M 10000

using namespace std;

vector<int> graph[MAX_N+1];
bool visited[MAX_N+1];

void BFS(int start){
	fill(visited, visited+MAX_N+1,false);
	queue<int> q;
	q.push(start);

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(visited[cur])
			continue;

		printf("%d ",cur);

		visited[cur] = true;
		for(int next: graph[cur]){
			if(visited[next] == false)
				q.push(next);
		}
	}
}

void DFS(int now){
	if(visited[now])
		return;

	printf("%d ",now);
	visited[now] = true;

	for(int next: graph[now]){
		if(visited[next] == false)
			DFS(next);
	}
}

int main(void)
{
    int N,M,V;
    scanf("%d %d %d", &N, &M, &V);

    for(int i=0;i<M;i++){
    	int a,b;
    	scanf("%d %d",&a,&b);
    	graph[a].push_back(b);
    	graph[b].push_back(a);
    }

    for(int i=1;i<=MAX_N;i++){
    	sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);
	printf("\n");
    BFS(V);
    printf("\n");

    return 0;
}