#include <stdio.h>
#include <queue>

#define MAX_N 1000
#define MAX_DIST 1e6

using namespace std;

int map[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int ROW,COL;

int rows[4] = {1,-1,0,0};
int cols[4] = {0,0,-1,1};

bool checkPosValid(int row, int col){
	if(row < 0 || row >= ROW || col < 0 || col >= COL)
		return false;
	if(map[row][col] == 0)
		return false;
	if(dist[row][col] != 0)
		return false;
	return true;
}

void BFS(pair<int,int> start){
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(start,0));

	while(!q.empty()){
		int curRow = q.front().first.first;
		int curCol = q.front().first.second;
		int curDist = q.front().second;
		q.pop();

		if(dist[curRow][curCol] != 0)
			continue;

		dist[curRow][curCol] = curDist;
		for(int i=0; i<4;i++){
			int nextRow = curRow + rows[i];
			int nextCol = curCol + cols[i];

			if(checkPosValid(nextRow,nextCol))
				q.push(make_pair(make_pair(nextRow,nextCol),curDist+1));
		}
	}

	dist[start.first][start.second] = MAX_DIST;
}

int main(void)
{
	scanf("%d %d",&ROW,&COL);

	pair<int,int> start;
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			scanf("%d",&map[i][j]);
			
			if(map[i][j] == 0)
				dist[i][j] = MAX_DIST;
			else if(map[i][j] == 2){
				start.first = i;
				start.second = j;
			}
		}
	}

	BFS(start);

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			int result = dist[i][j];
			
			if(dist[i][j] == 0)
				result = -1;
			else if(dist[i][j] == MAX_DIST)
				result = 0;
			printf("%d ",result);
		}
		printf("\n");
	}
    return 0;
}