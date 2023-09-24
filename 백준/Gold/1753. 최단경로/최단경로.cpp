#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>

#define MAX_V 20000
#define MAX_DIST INT_MAX

using namespace std;

// pair<dest, dist>
vector<pair<int,int> > graph[MAX_V+1];

bool visited[MAX_V+1];
int dist[MAX_V+1];

void dijkstra(int start){
	// pair<dist, dest>
	priority_queue<pair<int,int> > pq;

	dist[start] = 0;
	pq.push(make_pair(0,start));

	while(!pq.empty()){
		int curDist = -pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		if(visited[curPos])
			continue;

		visited[curPos] = true;
		for(pair<int,int> next : graph[curPos]){
			int nextDist = curDist + next.second;
			int nextPos = next.first;

			if(nextDist < dist[nextPos]){
				dist[nextPos] = nextDist;
				if(visited[nextPos] == false)
					pq.push(make_pair(-nextDist,nextPos));
			}
		}
	}
}

int main(void)
{
 	int V,E,K;
	scanf("%d %d %d",&V,&E,&K);

	for(int i=0;i<E;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);

		graph[u].push_back(make_pair(v,w));
	}

	for(int i=1;i<=V;i++)
		dist[i] = MAX_DIST;

	dijkstra(K);
	for(int i=1;i<=V;i++){
		if(dist[i] == INT_MAX)
			printf("INF\n");
		else printf("%d\n",dist[i]);
	}
    return 0;
}