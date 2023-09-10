#include <iostream>
#include <stdio.h>
#include <queue>

#define MAX_N 1000

using namespace std;

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};
int map[MAX_N][MAX_N];
int COL,ROW;
queue<pair<int,int> > startQ;
int target = 0;

bool checkPosValid(int row, int col){
	if(row < 0 || row >= ROW || col < 0 || col >= COL)
		return false;
	if(map[row][col])
		return false;
	return true;
}

int BFS(){
	if(target == 0)
		return 0;

	queue<pair<int,pair<int,int> > > q;
	while(!startQ.empty()){
		pair<int,int> start = startQ.front();
		startQ.pop();

		for(int i=0;i<4;i++){
			int nextRow = start.first + rows[i];
			int nextCol = start.second + cols[i];

			if(checkPosValid(nextRow,nextCol))
				q.push(make_pair(1,make_pair(nextRow,nextCol)));
		}
	}

	int cnt = 0;
	while(!q.empty()){
		int day = q.front().first;
		pair<int,int> cur = q.front().second;
		q.pop();

		if(map[cur.first][cur.second])
			continue;

		map[cur.first][cur.second] = 1;
		cnt++;

		if(cnt == target)
			return day;

		for(int i=0;i<4;i++){
			int nextRow = cur.first + rows[i];
			int nextCol = cur.second + cols[i];

			if(checkPosValid(nextRow,nextCol))
				q.push(make_pair(day+1,make_pair(nextRow,nextCol)));
		}
	}

	return -1;
}

int main(void)
{
	scanf("%d %d", &COL, &ROW);
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j] == 1)
				startQ.push(make_pair(i,j));
			else if(map[i][j] == 0)
				target++;
		}
	}

	printf("%d\n",BFS());
    return 0;
}