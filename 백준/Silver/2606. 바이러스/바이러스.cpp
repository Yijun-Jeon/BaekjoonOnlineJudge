#include <stdio.h>
#include <vector>
#include <queue>

#define MAX_N 100

using namespace std;

int N,E;
bool visited[MAX_N+1];
vector<int> graph[MAX_N+1];

int BFS(){
	queue<int> q;
	q.push(1);

	int cnt = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(visited[cur])
			continue;

		visited[cur] = true;
		cnt++;

		for(int next: graph[cur]){
			if(visited[next] == false)
				q.push(next);
		}
	}

	return cnt-1;
}

int main(void)
{
	scanf("%d",&N);
	scanf("%d",&E);

	for(int i=0;i<E;i++){
		int a,b;
		scanf("%d %d",&a,&b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	printf("%d\n", BFS());

    return 0;
}