#include <stdio.h>
#include <queue>

#define MAX_V 10000

using namespace std;

int V,E;
priority_queue<pair<int,pair<int,int> > > pq;
int parent[MAX_V+1];

int Find(int x){
	if(x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
	int parentX = Find(x);
	int parentY = Find(y);

	if(parentX != parentY)
		parent[parentY] = parentX;
}

int main(void)
{
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);

		pq.push(make_pair(-C,make_pair(A,B)));
	}

	for(int i=1;i<=MAX_V;i++)
		parent[i] = i;

	int cnt = 0;
	long long sum = 0;
	while(cnt < V-1){
		int curDist = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();
		if(Find(x) == Find(y))
			continue;

		Union(x,y);
		cnt++;
		sum += curDist;
	}
	printf("%lld\n",sum);
    return 0;
}