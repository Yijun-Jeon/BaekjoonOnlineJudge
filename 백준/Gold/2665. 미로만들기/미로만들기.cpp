#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX_N 50

using namespace std;

int N;
int map[MAX_N][MAX_N];
int erase[MAX_N][MAX_N];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col, int blackSum){
    if(row < 0 || row >= N || col < 0 || col >= N)
        return false;
    if(erase[row][col] <= blackSum)
        return false;
    return true;
}

void DFS(int row, int col, int blackSum){
    erase[row][col] = blackSum;

    if(row == N-1 && col == N-1)
        return;

    if(map[row][col] == 0)
        blackSum++;

    for(int i=0;i<4;i++){
        int nextRow = row + rows[i];
        int nextCol = col + cols[i];
        if(checkPosValid(nextRow,nextCol,blackSum))
            DFS(nextRow,nextCol,blackSum);
    }
}

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char line[N+1];
        scanf("%s",line);

        for(int j=0;j<N;j++)
            map[i][j] = line[j] - '0';
    }

    fill(&erase[0][0],&erase[N-1][N],MAX_N*MAX_N);

    DFS(0,0,0);

    printf("%d\n",erase[N-1][N-1]);
    return 0;
}