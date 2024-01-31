#include <stdio.h>
#include <algorithm>
#include <queue>

#define MAX_N 125
#define MAX_DIST 1125

using namespace std;

int N;
int map[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,1,-1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= N)
        return false;
    return true;
}

void dijkstra(){
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(0,0),map[0][0]));

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int cost = q.front().second;
        q.pop();

        if(dist[row][col] < cost)
            continue;

        dist[row][col] = cost;
        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol))
                q.push(make_pair(make_pair(nextRow,nextCol),cost+map[nextRow][nextCol]));
        }
    }

}

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int test_case = 0; test_case < T; test_case++){
        scanf("%d",&N);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                scanf("%d",&map[i][j]);
        }

        fill(&dist[0][0],&dist[N-1][N],MAX_DIST);

        dijkstra();

        printf("%d\n",dist[N-1][N-1]);
    }
    return 0;
}