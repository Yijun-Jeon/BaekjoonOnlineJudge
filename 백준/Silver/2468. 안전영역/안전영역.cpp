#include <stdio.h>
#include <cstring>
#include <queue>

#define MAX_N 100

using namespace std;

int N;
int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int rows[4] = {1,-1,0,0};
int cols[4] = {0,0,1,-1};

int checkPosValid(int row, int col, int high){
    if(row < 0 || row >= N || col < 0 || col >= N)
        return false;
    if(visited[row][col])
        return false;
    if(map[row][col] <= high)
        return false;
    return true;
}

void BFS(int row, int col, int high){
    queue<pair<int,int> > q;
    q.push(make_pair(row,col));

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(visited[r][c])
            continue;

        visited[r][c] = true;
        for(int i=0;i<4;i++){
            int nextRow = r + rows[i];
            int nextCol = c + cols[i];
            if(checkPosValid(nextRow,nextCol,high))
                q.push(make_pair(nextRow,nextCol));
        }
    }
}

int main(void)
{
    scanf("%d",&N);

    int maxHeight = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
            maxHeight = max(maxHeight,map[i][j]); 
        }
    }

    int result = 0;
    for(int h=0;h<maxHeight;h++){
        int safe = 0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(checkPosValid(i,j,h)){
                    BFS(i,j,h);
                    safe++;
                }
            }
        }
        result = max(result,safe);
    }
    printf("%d\n",result);
    return 0;
}