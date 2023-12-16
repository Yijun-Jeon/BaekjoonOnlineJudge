#include <stdio.h>
#include <vector>
#include <queue>

#define MAX_N 32000

using namespace std;

int N,M;
vector<int> graph[MAX_N+1];
int indegree[MAX_N+1];

int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);

		graph[a].push_back(b);
		indegree[b]++;
	}

	priority_queue<int> pq;
	for(int i=1;i<=N;i++){
		if(indegree[i] == 0)
			pq.push(-i);
	}

	while(!pq.empty()){
		int cur = -pq.top();
		printf("%d ",cur);
		pq.pop();

		for(int next: graph[cur]){
			indegree[next]--;
			if(indegree[next] == 0)
				pq.push(-next);
		}
	}
	printf("\n");
    return 0;
}