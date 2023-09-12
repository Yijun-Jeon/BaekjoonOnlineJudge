#include <stdio.h>
#include <queue>

#define MAX_N 100

using namespace std;

int trap[MAX_N+1];
bool visited[MAX_N+1];

bool checkPosValid(int nextPos){
	if(nextPos > MAX_N)
		return false;
	if(visited[nextPos])
		return false;
	return true;
}

int BFS(){
	queue<pair<int,int> > q;
	q.push(make_pair(1,0));

	while(!q.empty()){
		int curPos = q.front().first;
		int curDist = q.front().second;
		q.pop();

		if(visited[curPos])
			continue;

		if(curPos == MAX_N)
			return curDist;

		visited[curPos] = true;
		for(int i=6;i>0;i--){
			int nextPos = curPos + i;
			if(checkPosValid(nextPos))
				q.push(make_pair(nextPos + trap[nextPos],curDist+1));
		}
	}

	return -1;
}

int main(void)
{
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d %d",&x,&y);

		trap[x] = y - x;
	}

	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d %d",&u,&v);

		trap[u] = v - u;
	}

	printf("%d\n",BFS());
    return 0;
}