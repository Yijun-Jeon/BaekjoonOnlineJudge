#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 100
#define MAX_DIST MAX_N * MAX_N

using namespace std;

int ROW,COL;
int dist[MAX_N+1][MAX_N+1][3];
char map[MAX_N+1][MAX_N+1];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

queue<pair<pair<int,int>, pair<int,int> > > q;

bool checkPosValid(int row, int col, int d, int p){
    if(row <= 0 || row > ROW || col <= 0 || col > COL)
        return false;
    if(map[row][col] == '1')
        return false;
    if(dist[row][col][p] <= d)
        return false;
    return true;
}

void BFS(){
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int d = q.front().second.first;
        int p = q.front().second.second;
        q.pop();

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol,d+1,p)){
                q.push(make_pair(make_pair(nextRow,nextCol),make_pair(d+1,p)));
                dist[nextRow][nextCol][p] = d+1;
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> ROW >> COL;
    for(int r=1;r<=ROW;r++){
        for(int c=1;c<=COL;c++)
            cin >> map[r][c];
    }

    fill(&dist[0][0][0], &dist[ROW][COL][3], MAX_DIST+2);
    for(int i=0;i<3;i++){
        int row,col;
        cin >> row >> col;

        q.push(make_pair(make_pair(row,col),make_pair(0,i)));
        dist[row][col][i] = 0;
    }

    BFS();

    int minTime = MAX_DIST+1, cnt = 0;
    for(int r=1;r<=ROW;r++){
        for(int c=1;c<=COL;c++){
            int temp = max(dist[r][c][0],max(dist[r][c][1],dist[r][c][2]));
            if(minTime == temp) cnt++;
            if(temp < minTime){
                minTime = temp;
                cnt = 1;
            }
        }
    }
    if(cnt == 0) cout << -1 << '\n';
    else cout << minTime << '\n' << cnt << '\n';
    return 0;
}