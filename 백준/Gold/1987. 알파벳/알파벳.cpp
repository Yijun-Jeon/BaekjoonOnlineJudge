#include <stdio.h>

#define MAX_N 20

using namespace std;

bool alpha[26];
char map[MAX_N+1][MAX_N+1];
int R,C;
int result = 0;

int rows[4] = {1,-1,0,0};
int cols[4] = {0,0,1,-1};

bool checkPosValid(int row, int col){
	if(row <= 0 || row > R || col <= 0 || col > C)
		return false;
	if(alpha[map[row][col]-'A'])
		return false;
	return true;
}

void DFS(int row, int col, int sum){
	if(alpha[map[row][col] - 'A'])
		return;

	if(result < sum)
		result = sum;

	alpha[map[row][col] - 'A'] = true;
	for(int i=0;i<4;i++){
		int nextRow = row + rows[i];
		int nextCol = col + cols[i];

		if(checkPosValid(nextRow,nextCol))
			DFS(nextRow,nextCol,sum+1);
	}
	alpha[map[row][col] - 'A'] = false;
}

int main(void)
{
	scanf("%d %d",&R,&C);
	for(int i=1;i<=R;i++){
		char temp[MAX_N+1];
		scanf("%s",temp);

		for(int j=1;j<=C;j++)
			map[i][j] = temp[j-1];
	}

	DFS(1,1,1);
	printf("%d\n",result);
    return 0;
}