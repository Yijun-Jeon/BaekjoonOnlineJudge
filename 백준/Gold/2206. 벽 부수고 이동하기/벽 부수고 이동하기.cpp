#include <stdio.h>
#include <queue>

#define MAX_N 1000
#define MAX_DIST 1000000

using namespace std;

int ROW,COL;
int map[MAX_N+1][MAX_N+1];
int dist[2][MAX_N+1][MAX_N+1];
int rows[4] = {1,-1,0,0};
int cols[4] = {0,0,1,-1};

bool checkPosValid(int row, int col, int curDist){
	if(row <= 0 || row > ROW || col <= 0 || col > COL)
		return false;
	return true;
}

int BFS(){
	queue<pair< pair<int,bool>, pair<int,int> > > q;
	q.push(make_pair(make_pair(1,false),make_pair(1,1)));

	while(!q.empty()){
		int curDist = q.front().first.first;
		bool curBroken = q.front().first.second;
		int curRow = q.front().second.first;
		int curCol = q.front().second.second;
		q.pop();

		if(dist[curBroken][curRow][curCol] <= curDist)
			continue;

		if(curRow == ROW && curCol == COL)
			return curDist;

		dist[curBroken][curRow][curCol] = curDist;
		for(int i=0;i<4;i++){
			int nextRow = curRow + rows[i];
			int nextCol = curCol + cols[i];

			if(checkPosValid(nextRow,nextCol,curDist+1)){
				if(curBroken){
					if(map[nextRow][nextCol] == 0)
						q.push(make_pair(make_pair(curDist+1,true),make_pair(nextRow,nextCol)));
				}else{
					if(map[nextRow][nextCol] == 0)
						q.push(make_pair(make_pair(curDist+1,false),make_pair(nextRow,nextCol)));
					else
						q.push(make_pair(make_pair(curDist+1,true),make_pair(nextRow,nextCol)));
				}
			}
		}
	}

	return -1;
}

int main(void)
{
	scanf("%d %d",&ROW,&COL);
	for(int i=1;i<=ROW;i++){
		char line[COL];
		scanf("%s",line);

		for(int j=0;j<COL;j++){
			map[i][j+1] = line[j] - '0';
			dist[0][i][j+1] = MAX_DIST;
			dist[1][i][j+1] = MAX_DIST;
		}
	}

	printf("%d\n",BFS());
    return 0;
}