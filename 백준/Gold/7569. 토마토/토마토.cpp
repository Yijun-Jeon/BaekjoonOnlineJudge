#include <stdio.h>
#include <queue>

#define MAX_N 100

using namespace std;

int floors[6] = {-1,1,0,0,0,0};
int rows[6] = {0,0,-1,1,0,0};
int cols[6] = {0,0,0,0,-1,1};

int map[MAX_N][MAX_N][MAX_N];
int FLOOR,COL,ROW;
queue<pair<int,pair<int,int> > > startQ;
int target = 0;

bool checkPosValid(int floor, int row, int col){
	if(row < 0 || row >= ROW || col < 0 || col >= COL || floor < 0 || floor >= FLOOR)
		return false;
	if(map[floor][row][col])
		return false;
	return true;
}

int BFS(){
	if(target == 0)
		return 0;	

	queue<pair<int,pair<int,pair<int,int> > > > q;
	while(!startQ.empty()){
		pair<int,pair<int,int> > start = startQ.front();
		startQ.pop();

		for(int i=0;i<6;i++){
			int nextFloor = start.first + floors[i];
			int nextRow = start.second.first + rows[i];
			int nextCol = start.second.second + cols[i];

			if(checkPosValid(nextFloor,nextRow,nextCol))
				q.push(make_pair(1,make_pair(nextFloor,make_pair(nextRow,nextCol))));
		}
	}

	int cnt = 0;
	while(!q.empty()){
		int day = q.front().first;
		pair<int,pair<int,int> > cur = q.front().second;
		q.pop();

		if(map[cur.first][cur.second.first][cur.second.second])
			continue;

		map[cur.first][cur.second.first][cur.second.second] = 1;
		cnt++;

		if(cnt == target)
			return day;

		for(int i=0;i<6;i++){
			int nextFloor = cur.first + floors[i];
			int nextRow = cur.second.first + rows[i];
			int nextCol = cur.second.second + cols[i];

			if(checkPosValid(nextFloor,nextRow,nextCol))
				q.push(make_pair(day+1,make_pair(nextFloor,make_pair(nextRow,nextCol))));
		}
	}

	return -1;
}

int main(void)
{
	scanf("%d %d %d", &COL, &ROW, &FLOOR);
	for(int i=0;i<FLOOR;i++){
		for(int j=0;j<ROW;j++){
			for(int w=0;w<COL;w++){
				scanf("%d",&map[i][j][w]);
				if(map[i][j][w] == 1)
					startQ.push(make_pair(i,make_pair(j,w)));
				else if(map[i][j][w] == 0)
					target++;
			}
		}	
	}
	

	printf("%d\n",BFS());
    return 0;
}