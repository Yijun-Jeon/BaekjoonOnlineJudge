#include <stdio.h>
#include <queue>

#define MAX_N 100000

using namespace std;

int N;
vector<int> graph[MAX_N+1];
bool visited[MAX_N+1];
int parents[MAX_N+1];

void BFS(int start){
	queue<pair<int,int> > q;
	q.push(make_pair(1,0));

	while(!q.empty()){
		int cur = q.front().first;
		int parent = q.front().second;
		q.pop();

		if(visited[cur])
			continue;

		parents[cur] = parent;
		visited[cur] = true;

		for(int next: graph[cur]){
			if(visited[next] == false)
				q.push(make_pair(next,cur));
		}
	}
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

	BFS(1);

	for(int i=2;i<=N;i++)
		printf("%d\n",parents[i]);
    return 0;
}