#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX_N 125
#define MAX_DIST 1e9

using namespace std;

int dist[MAX_N][MAX_N];
int map[MAX_N][MAX_N];
int N;

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= N)
        return false;
    return true;
}

void BFS(){
    queue<pair<int,pair<int,int> > > q;
    q.push(make_pair(0,make_pair(0,0)));

    while(!q.empty()){
        int curDist = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        if(dist[row][col] <= curDist + map[row][col])
            continue;
        
        dist[row][col] = curDist + map[row][col];
        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol)){
                if(dist[nextRow][nextCol] > dist[row][col] + map[nextRow][nextCol])
                q.push(make_pair(dist[row][col],make_pair(nextRow,nextCol)));
            }
        }
    }
}

int main(void)
{
    int t = 0;
    while(++t){        
        scanf("%d",&N);
        if(N == 0)
            break;

        fill(&dist[0][0],&dist[N-1][N],MAX_DIST);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                scanf("%d",&map[i][j]);
        }

        BFS();

        printf("Problem %d: %d\n",t,dist[N-1][N-1]);
    }
    return 0;
}