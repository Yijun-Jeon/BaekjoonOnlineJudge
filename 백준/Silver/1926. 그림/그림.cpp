#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 500

using namespace std;

int N,M;
bool map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= M)
        return false;
    if(map[row][col] == 0)
        return false;
    if(visited[row][col])
        return false;
    return true;
}

int BFS(int r, int c){
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));
    visited[r][c] = true;

    int extent = 0;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        extent++;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol)){
                visited[nextRow][nextCol] = true;
                q.push(make_pair(nextRow,nextCol));
            }
        }
    }
    return extent;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    int cnt = 0, result = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] && visited[i][j] == false){
                result = max(result,BFS(i,j));
                cnt++;
            }
        }
    }
    cout << cnt << '\n' << result << '\n';
    return 0;
}