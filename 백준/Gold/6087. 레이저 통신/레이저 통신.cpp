#include <stdio.h>
#include <algorithm>
#include <queue>

#define MAX_N 100
#define MAX_MIRROR 10000

using namespace std;

int COL,ROW;
char map[MAX_N][MAX_N];
int mirrors[MAX_N][MAX_N][4];

// 북, 동, 남, 서
int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col,int dir, int mirror){
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if(map[row][col] == '*')
        return false;
    if(mirrors[row][col][dir] <= mirror)
        return false;
    return true;
}

void BFS(int startRow, int startCol){
    // pair<row,col>, pair<mirror,dir>
    queue<pair<pair<int,int>,pair<int,int> > > q;
    for(int i=0;i<4;i++){
        mirrors[startRow][startCol][i] = 0;
        int nextRow = startRow + rows[i];
        int nextCol = startCol + cols[i];
        if(checkPosValid(nextRow,nextCol,i,0))
            q.push(make_pair(make_pair(nextRow,nextCol),make_pair(0,i)));
    }

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int mirror = q.front().second.first;
        int dir = q.front().second.second;
        q.pop();

        if(mirrors[row][col][dir] <= mirror)
            continue;
        mirrors[row][col][dir] = mirror;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            int nextMirror = dir == i ? mirror : mirror+1;
            if(checkPosValid(nextRow,nextCol,i,nextMirror)){
                q.push(make_pair(make_pair(nextRow,nextCol),make_pair(nextMirror,i)));
            }
        }
    }
}

int main(void)
{
    scanf("%d %d",&COL,&ROW);

    queue<pair<int,int> > CQ;

    for(int r=0;r<ROW;r++){
        char line[COL+1];
        scanf("%s",line);
        for(int c=0;c<COL;c++){
            map[r][c] = line[c];

            if(map[r][c] == 'C'){
                CQ.push(make_pair(r,c));
            }
        }
    }

    fill(&mirrors[0][0][0],&mirrors[ROW-1][COL-1][4],MAX_MIRROR);

    BFS(CQ.front().first,CQ.front().second);
    CQ.pop();

    int result = MAX_MIRROR;
    for(int i=0;i<4;i++)
        result = min(result,mirrors[CQ.front().first][CQ.front().second][i]);

    printf("%d\n",result);

    return 0;
}