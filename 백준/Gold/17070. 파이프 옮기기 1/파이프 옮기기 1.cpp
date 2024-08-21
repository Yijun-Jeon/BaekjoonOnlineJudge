#include <stdio.h>

#define MAX_N 16

using namespace std;

int N,result;
int map[MAX_N][MAX_N];

// 가로, 세로, 대각 순서
int rows[3][3] = {0,1,MAX_N+1,1,1,MAX_N+1,0,1,1};
int cols[3][3] = {1,1,MAX_N+1,0,1,MAX_N+1,1,0,1};
int statuses[3][3]={0,2,0,1,2,0,0,1,2};

bool checkPosValid(int row, int col, int status){
    if(row<0 || row>=N || col<0 || col>= N)
        return false;
    if(map[row][col])
        return false;
    if(status == 2)
        return !(map[row-1][col] || map[row][col-1]);
    return true;
}

void DFS(int row, int col, int status){
    if(row == N-1 && col == N-1){
        result++;
        return;
    }

    for(int i=0;i<3;i++){
        int nextStatus = statuses[status][i];
        int nextRow = row + rows[status][i];
        int nextCol = col + cols[status][i];
        
        if(checkPosValid(nextRow,nextCol,nextStatus))
            DFS(nextRow,nextCol,nextStatus);
    }
}

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            scanf("%d",&map[i][j]);
    }

    DFS(0,1,0);

    printf("%d\n",result);
    return 0;
}