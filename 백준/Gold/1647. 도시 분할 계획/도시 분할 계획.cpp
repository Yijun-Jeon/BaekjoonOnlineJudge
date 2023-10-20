#include <iostream>
#include <stdio.h>
#include <queue>

#define MAX_N 100000

using namespace std;

int parent[MAX_N+1];
priority_queue<pair<int,pair<int,int> > > pq;
int N,M;

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
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
		parent[i] = i;

	for(int i=0;i<M;i++){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		pq.push(make_pair(-C, make_pair(A,B)));
	}

	int sum = 0;
	int edge = 0;
	while(edge < N-2){
		int dist = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();
		if(Find(x) == Find(y))
			continue;

		Union(x,y);
		edge++;
		sum += dist;
	}
	printf("%d\n",sum);
    return 0;
}