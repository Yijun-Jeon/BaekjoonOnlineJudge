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

	queue<int> q;
	for(int i=1;i<=N;i++)
		if(indegree[i] == 0)
			q.push(i);

	while(!q.empty()){
		int cur = q.front();
		printf("%d ",cur);
		q.pop();

		for(int next: graph[cur]){
			indegree[next]--;
			if(indegree[next] == 0)
				q.push(next);
		}
	}
	printf("\n");
    return 0;
}