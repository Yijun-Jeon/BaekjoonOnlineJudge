#include <stdio.h>
#include <stdio.h>
#include <queue>

#define MAX_N 600

using namespace std;

int N,M;
char map[MAX_N][MAX_N];

int rows[4] = {1,-1,0,0};
int cols[4] = {0,0,-1,1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= M)
        return false;
    if(map[row][col] == 'X')
        return false;
    return true;
}

int BFS(int row, int col){
    int result = 0;
    queue<pair<int,int> > q;

    q.push(make_pair(row,col));
    while(!q.empty()){
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        if(map[curRow][curCol] == 'T')
            continue;
        if(map[curRow][curCol] == 'P')
            result++;
        
        map[curRow][curCol] = 'T';
        for(int i=0;i<4;i++){
            int nextRow = curRow + rows[i];
            int nextCol = curCol + cols[i];
            if(checkPosValid(nextRow,nextCol)){
                q.push(make_pair(nextRow,nextCol));
            }
        }
    }

    return result;
}

int main(void)
{
    int row,col;
    scanf("%d %d",&N,&M);
    getchar();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1c",&map[i][j]);

            if(map[i][j] == 'I')
                row = i, col = j;
        }
        getchar();
    }

    int result = BFS(row,col);
    if(result == 0) printf("TT\n");
    else printf("%d\n",result);
    return 0;
}