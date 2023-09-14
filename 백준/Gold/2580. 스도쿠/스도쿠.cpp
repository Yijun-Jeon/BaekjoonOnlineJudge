#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

// [row / 3 * 3 + col / 3][row % 3 * 3 + col % 3]
int squares[9][9];
int board[9][9];
vector<pair<int,int> > blanks;
bool found = false;

bool isNumOk(int row, int col, int num){
	for(int i=0; i<9; i++){
		// 가로 검사
		if(board[row][i] == num)
			return false;
		// 세로 검사
		if(board[i][col] == num)
			return false;
		// 정사각형 검사
		if(squares[row/3*3 + col/3][i] == num)
			return false;
	}

	return true;
}

void DFS(int idx){
	if(idx == blanks.size()){
		found = true;
		return;
	}

	int row = blanks[idx].first;
	int col = blanks[idx].second;
	for(int num = 1; num <= 9; num++){
		if(isNumOk(row, col, num)){
			board[row][col] = num;
			squares[row/3*3 + col/3][row%3*3 + col%3] = num;

			DFS(idx+1);
			if(found)
				return;

			board[row][col] = 0;
			squares[row/3*3 + col/3][row%3*3 + col%3] = 0;
		}
	}
}


int main(void)
{
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			scanf("%d",&board[i][j]);
			squares[i/3*3 + j/3][i%3*3 + j%3] = board[i][j];
			if(board[i][j] == 0){
				blanks.push_back(make_pair(i,j));
			}
		}
	}

	DFS(0);

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
    return 0;
}