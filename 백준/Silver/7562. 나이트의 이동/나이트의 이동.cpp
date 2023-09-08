#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

#define MAX_I 300

using namespace std;

int I;
int rows[8] = {-1,-1,-2,-2,1,1,2,2};
int cols[8] = {-2,2,-1,1,-2,2,-1,1};
int visited[MAX_I][MAX_I];
int rowTarget, colTarget;

bool checkPosValid(int row, int col){
	if(row < 0 || row >= I || col < 0 || col >= I)
		return false;
	if(visited[row][col])
		return false;
	return true;
}

int BFS(int rowNow, int colNow){
	priority_queue<pair<int,pair<int,int> > > pq;
	pq.push(make_pair(0,make_pair(rowNow,colNow)));

	while(!pq.empty()){
		int curCnt = -pq.top().first;
		int curRow = pq.top().second.first;
		int curCol = pq.top().second.second;
		pq.pop();

		if(visited[curRow][curCol])
			continue;

		if(curRow == rowTarget && curCol == colTarget)
			return curCnt;

		visited[curRow][curCol] = true;
		for(int i=0;i<8;i++){
			int nextRow = curRow + rows[i];
			int nextCol = curCol + cols[i];

			if(checkPosValid(nextRow,nextCol))
				pq.push(make_pair(-(curCnt+1),make_pair(nextRow,nextCol)));
		}
	}

	return -1;
}

int main(void)
{
	int T;
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		scanf("%d",&I);

		int rowNow, colNow;
		scanf("%d %d", &rowNow, &colNow);
		scanf("%d %d", &rowTarget, &colTarget);

		memset(visited,false,sizeof(visited));

		printf("%d\n",BFS(rowNow,colNow));
	}
    return 0;
}