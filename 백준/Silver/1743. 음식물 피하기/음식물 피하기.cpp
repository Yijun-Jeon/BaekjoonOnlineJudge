#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 100

using namespace std;

bool visited[MAX_N+1][MAX_N+1];
bool map[MAX_N+1][MAX_N+1];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

int N,M,K;

bool checkPosValid(int row, int col){
    if(row <= 0 || row > N || col <= 0 || col > M)
        return false;
    if(visited[row][col])
        return false;
    return map[row][col];
}

int BFS(int r, int c){
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));

    int size = 0;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(visited[row][col])
            continue;
        visited[row][col] = true;
        size++;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol))
                q.push(make_pair(nextRow,nextCol));
        }
    }
    return size;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    for(int i=0;i<K;i++){
        int r,c;
        cin >> r >> c;

        map[r][c] = true;
    }

    int result = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(map[i][j] && visited[i][j] == false)
                result = max(result, BFS(i,j));
        }
    }
    cout << result << '\n';
    return 0;
}