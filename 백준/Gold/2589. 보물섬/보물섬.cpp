#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX_N 50

using namespace std;

int ROW,COL;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if(map[row][col] == 'W')
        return false;
    if(visited[row][col])
        return false;
    return true;
}

int BFS(int r, int c){
    memset(visited,false,sizeof(visited));

    int maxDist = 0;
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(r,c),0));
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if(visited[row][col])
            continue;
        visited[row][col] = true;

        maxDist = max(maxDist,dist);
        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol))
                q.push(make_pair(make_pair(nextRow,nextCol),dist+1));
        }
    }
    return maxDist;
}

int main(void)
{
    scanf("%d %d",&ROW,&COL);
    for(int i=0;i<ROW;i++){
        char row[COL+1];
        scanf("%s",row);
        for(int j=0;j<COL;j++){
            map[i][j] = row[j];
        }
    }

    int result = 0;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(map[i][j] == 'L')
                result = max(result,BFS(i,j));
        }
    }
    printf("%d\n",result);
    return 0;
}