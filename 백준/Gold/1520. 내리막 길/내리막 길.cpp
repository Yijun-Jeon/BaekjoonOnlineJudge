#include <stdio.h>
#include <cstring>

#define MAX_N 500

using namespace std;

int map[MAX_N][MAX_N];
int ROW,COL;
int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};

int visited[MAX_N][MAX_N];

bool checkPosValid(int row, int col, int lastHeight){
	if(row < 0 || row >= ROW || col < 0 || col >= COL)
		return false;
	if(map[row][col] >= lastHeight)
		return false;
	return true;
}

int DFS(int curRow, int curCol){
	if(curRow == ROW-1 && curCol == COL-1){
		return 1;
	}

 	int &result = visited[curRow][curCol];
	if(result != -1)
		return result;

	result = 0;

	for(int i=0;i<4;i++){
		int nextRow = curRow + rows[i];
		int nextCol = curCol + cols[i];

		if(checkPosValid(nextRow,nextCol,map[curRow][curCol]))
			result += DFS(nextRow,nextCol);
	}
	
	return result;
}

int main(void)
{
	scanf("%d %d",&ROW, &COL);
	for(int row=0;row<ROW;row++){
		for(int col=0;col<COL;col++)
			scanf("%d",&map[row][col]);
	}
	memset(visited,-1,sizeof(visited));

	printf("%d\n",DFS(0,0));
    return 0;
}