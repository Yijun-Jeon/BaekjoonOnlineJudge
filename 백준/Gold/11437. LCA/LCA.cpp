#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_N 50000
#define MAX_K 16

using namespace std;

int N,M;
vector<int> graph[MAX_N+1];
int parents[MAX_K+1][MAX_N+1];

int depth[MAX_N+1];
int visited[MAX_N+1];

void BFS(){
	queue<pair<int,int> > q;
	q.push(make_pair(1,0));

	while(!q.empty()){
		int cur = q.front().first;
		int curDepth = q.front().second;
		q.pop();

		if(visited[cur])
			continue;

		visited[cur] = true;
		depth[cur] = curDepth;
		for(int child: graph[cur]){
			if(visited[child] == false){
				parents[0][child] = cur;
				q.push(make_pair(child,curDepth+1));
			}
		}
	}
}

int LCA(int x, int y){
	if(depth[x] > depth[y])
		swap(x,y);


    for(int k=MAX_K; k>=0; k--){
        if(pow(2,k) <= depth[y] - depth[x])
            y = parents[k][y];
    }

	if(x == y)
		return x;

	for(int k=MAX_K;k>=0;k--){
		if(parents[k][x] != parents[k][y]){
			x = parents[k][x];
			y = parents[k][y];
		}
	}

	x = parents[0][x];

	return x;
}

int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	BFS();

	for(int k=1;k<=MAX_K;k++){
		for(int i=2;i<=N;i++){
			parents[k][i] = parents[k-1][parents[k-1][i]];
		}
	}

	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",LCA(x,y));
	}
    return 0;
}