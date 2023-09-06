#include <stdio.h>
#include <queue>
#include <utility>

#define MAX_N 100

using namespace std;

int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int rows[4] = {0,0,1,-1};
int cols[4] = {1,-1,0,0};
int N,M;

bool checkPosValid(int row, int col){
	if(row < 0 || row >= N || col < 0 || col >= M)
		return false;
	if(visited[row][col])
		return false;
	if(map[row][col] == 0)
		return false;
	return true;
}

int BFS(pair<int,pair<int,int> > start){
	queue<pair<int, pair<int,int> > > q;
	q.push(start);

	while(!q.empty()){
		int curDist = q.front().first;
		pair<int,int> curPos = q.front().second;
		q.pop();

		if(visited[curPos.first][curPos.second])
			continue;

		if(curPos.first == N-1 && curPos.second == M-1)
			return curDist;

		visited[curPos.first][curPos.second] = true;
		for(int i=0;i<4;i++){
			int nextRow = curPos.first + rows[i];
			int nextCol = curPos.second + cols[i];
			if(checkPosValid(nextRow,nextCol))
				q.push(make_pair(curDist+1,make_pair(nextRow,nextCol)));
		}
	}
	return -1;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for(int i=0;i<N;i++){
		char line[M];
		scanf("%s",line);
		for(int j=0;j<M;j++)
			map[i][j] = line[j]-'0';
	}

	printf("%d\n",BFS(make_pair(1,make_pair(0,0))));
    return 0;
}