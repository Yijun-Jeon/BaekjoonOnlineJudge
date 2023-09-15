#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX_N 1000
#define MAX_M 100000

using namespace std;

int N,M;
int parent[MAX_N+1];
priority_queue<pair<int,pair<int,int> > > pq;

int Find(int x){
	if(parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
	if(Find(x) == Find(y))
		return;
	parent[Find(y)] = Find(x);
}

int kruskal(){
	int cost = 0;
	int m = 0;

	while(!pq.empty() && m < N-1){
		int curCost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if(Find(x) == Find(y))
			continue;

		Union(x,y);
		cost += curCost;
		m++;
	}
	return cost;
}

int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
		parent[i] = i;

	for(int i=0;i<M;i++){
		int x,y,dist;
		scanf("%d %d %d",&x,&y,&dist);

		pq.push(make_pair(-dist,make_pair(x,y)));
	}

	printf("%d\n",kruskal());
    return 0;
}