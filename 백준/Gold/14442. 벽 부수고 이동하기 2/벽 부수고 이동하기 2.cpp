#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 1000
#define MAX_DIST 1e6
#define MAX_K 10

using namespace std;

int ROW,COL,K;
char map[MAX_N+1][MAX_N+1];
int dist[MAX_N+1][MAX_N+1][MAX_K+1];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col, int d, int broken){
    if(row <= 0 || row > ROW || col <= 0 || col > COL)
        return false;
    if(map[row][col] == '1' && broken > K)
        return false;
    if(dist[row][col][broken] <= d)
        return false;
    return true;
}

void BFS(){
    fill(&dist[0][0][0],&dist[ROW][COL][K+1],MAX_DIST);

    queue<pair<pair<int,int>,pair<int,int> > > q;
    q.push(make_pair(make_pair(1,1),make_pair(1,0)));

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int d = q.front().second.first;
        int broken = q.front().second.second;
        q.pop();

        if(dist[row][col][broken] <= d)
            continue;
        dist[row][col][broken] = d;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            int nextDist = d+1;
            int nextBrokken = map[nextRow][nextCol] == '1' ? broken+1 : broken;
            if(checkPosValid(nextRow,nextCol,nextDist,nextBrokken))
                q.push(make_pair(make_pair(nextRow,nextCol),make_pair(nextDist,nextBrokken)));
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> ROW >> COL >> K;

    for(int r=1;r<=ROW;r++){
        for(int c=1;c<=COL;c++)
            cin >> map[r][c];
    }

    BFS();

    int result = MAX_DIST;
    for(int k=0;k<=K;k++)
        result = min(result,dist[ROW][COL][k]);

    if(result == MAX_DIST) result = -1;
    cout << result << '\n';
    return 0;
}