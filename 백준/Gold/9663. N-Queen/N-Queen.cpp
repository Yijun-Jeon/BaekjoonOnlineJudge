#include <stdio.h>
#include <cmath>
#include <cstring>

#define MAX_N 15

using namespace std;

int board[MAX_N];
int N;
int result = 0;

bool okQueen(int row, int col){
	for(int r = 0; r < row; r++){
		if(board[r] == col)
			return false;
		if(abs(r - row) == abs(board[r] - col))
			return false;
	}
	return true;
}

void DFS(int row){
	if(row == N){
		result++;
		return;
	}
	for(int col=0;col<N;col++){
		if(okQueen(row,col)){
			board[row] = col;
			DFS(row+1);
			board[row] = -1;
		}
	}
}

int main(void)
{
	scanf("%d",&N);
	memset(board,-1,sizeof(board));
	DFS(0);
	printf("%d\n",result);
    return 0;
}