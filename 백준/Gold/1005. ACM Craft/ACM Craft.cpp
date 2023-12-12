#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX_N 1000

using namespace std;

int times[MAX_N+1];
int results[MAX_N+1];
vector<int> graph[MAX_N+1];

void init(){
	memset(times,0,sizeof(times));
	memset(results,0,sizeof(results));

	for(int i=0;i<=MAX_N;i++)
		graph[i].clear();
}

int DFS(int start){
	if(times[start] ==  -1)
		return results[start];

	if(graph[start].size() == 0)
		return results[start];

	for(int prev: graph[start]){
		results[start] = max(DFS(prev) + times[start],results[start]);
	}

	times[start] = -1;
	return results[start];
}

int main(void)
{
	int T;
	scanf("%d",&T);

	for(int test_case = 0; test_case < T; test_case++){
		init();

		int N,K;
		scanf("%d %d",&N,&K);

		for(int i=1;i<=N;i++){
			scanf("%d",&times[i]);
			results[i] = times[i];
		}

		for(int i=0;i<K;i++){
			int X,Y;
			scanf("%d %d",&X,&Y);
			graph[Y].push_back(X);
		}
		
		int W;
		scanf("%d",&W);
		printf("%d\n",DFS(W));
	}
    return 0;
}