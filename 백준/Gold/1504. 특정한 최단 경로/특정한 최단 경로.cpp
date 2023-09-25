#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 800
#define MAX_DIST 1e9

using namespace std;

// pair<node, dist>
vector<pair<int,int> > graph[MAX_N+1];
int dist[MAX_N+1];
bool visited[MAX_N+1];

int N,E;

// pair<dist, v>
void dijkstra(int start){
	for(int i=0;i<=N;i++){
		dist[i] = MAX_DIST;
		visited[i] = false;
	}

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
		for(auto next : graph[curPos]){
			int nextDist = curDist + next.first;
			int nextPos = next.second;

			if(nextDist < dist[nextPos]){
				dist[nextPos] = nextDist;
				if(visited[nextPos] == false)
					pq.push(make_pair(-nextDist, nextPos));
			}
		}
	}
}

int getResult(int v1, int v2){
	int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;
	dijkstra(1);
	sToV1 = dist[v1];
	sToV2 = dist[v2];

	dijkstra(v1);
	V1ToV2 = dist[v2];
	V1ToN = dist[N];

	dijkstra(v2);
	V2ToN = dist[N];

	int case1 = sToV1 + V1ToV2 + V2ToN;
	int case2 = sToV2 + V1ToV2 + V1ToN;

	if(V1ToV2 == MAX_DIST || min(case1,case2) >= MAX_DIST)
		return -1;
	else
		return min(case1,case2);
}

int main(void)
{
	scanf("%d %d",&N,&E);
	for(int i=0;i<E;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);	

		graph[a].push_back(make_pair(c,b));
		graph[b].push_back(make_pair(c,a));
	}

	int v1,v2;
	scanf("%d %d",&v1,&v2);

	printf("%d\n",getResult(v1,v2));
    return 0;
}