#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX_N 2000

using namespace std;

vector<int> graph[MAX_N];
int N,M;
bool visited[MAX_N];

bool DFS(int cur, int depth){
	if(depth == 5)
		return true;

	visited[cur] = true;
	for(int next: graph[cur]){
		if(visited[next] == false){
			if(DFS(next, depth+1))
				return true;
		}
	}
	visited[cur] = false;
	return false;
}

int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bool answer = false;
	for(int i=0;i<N;i++){
		memset(visited,false,sizeof(visited));
		if(DFS(i,1)){
			answer = true;
			break;
		}
	}

	printf("%d\n",answer);
    return 0;
}