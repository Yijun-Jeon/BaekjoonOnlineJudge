#include <stdio.h>
#include <cstring>
#include <queue>

#define MAX_N 500

using namespace std;

int n,m;
vector<int> graph[MAX_N+1];
bool visited[MAX_N+1];


bool BFS(int start){
	bool isTree = true;
	queue<pair<int,int> > q;
	q.push(make_pair(start,start));

	while(!q.empty()){
		int cur = q.front().first;
		int last = q.front().second;
		q.pop();

		if(visited[cur])
			continue;

		visited[cur] = true;
		for(int next: graph[cur]){
			if(next == last)
				continue;
			if(visited[next])
				isTree = false;
			else q.push(make_pair(next,cur));
		}
	}
	return isTree;
}

int main(void)
{
	int test_case = 0;
	while(true){
		test_case++;
		
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0)
			break;

		for(int i=1;i<=n;i++)
			graph[i].clear();

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		memset(visited,false,sizeof(visited));

		int tree = 0;
		for(int i=1; i<=n;i++){
			if(!visited[i])
				tree += BFS(i);
		}
		if(tree == 0)
			printf("Case %d: No trees.\n",test_case);	
		else if(tree == 1)
			printf("Case %d: There is one tree.\n",test_case);
		else
			printf("Case %d: A forest of %d trees.\n",test_case,tree);
	}		
    return 0;
}