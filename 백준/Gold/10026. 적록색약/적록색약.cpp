#include <iostream>
#include <string>
#include <cstring>
#include <queue>

#define MAX_N 100

using namespace std;

int N;
char map[MAX_N][MAX_N];

bool visited[MAX_N][MAX_N];
int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,1,-1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= N)
        return false;
    if(visited[row][col])
        return false;
    return true;
}

void BFS(int r, int c, bool isNormal){
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(visited[row][col])
            continue;

        visited[row][col] = true;
        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol)){
                // R == G
                if(!isNormal && (map[r][c] == 'R' || map[r][c] == 'G') &&
                    (map[nextRow][nextCol] == 'R' || map[nextRow][nextCol] == 'G'))
                    q.push(make_pair(nextRow,nextCol));
                else if(map[r][c] == map[nextRow][nextCol])
                    q.push(make_pair(nextRow,nextCol));             
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0;i<N;i++){
        string row;
        cin >> row;

        for(int j=0;j<N;j++)
            map[i][j] = row[j];
    }

    int result1 = 0, result2 = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] == false){
                BFS(i,j,true);
                result1++;
            }
        }
    }
    memset(visited,false,sizeof(visited));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] == false){
                BFS(i,j,false);
                result2++;
            }
        }
    }
    cout << result1 << " " << result2 << '\n';
    return 0;
}