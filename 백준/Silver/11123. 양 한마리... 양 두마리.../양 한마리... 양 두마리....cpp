#include <iostream>
#include <cstring>
#include <queue>

#define MAX_N 100

using namespace std;

int ROW,COL;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if(map[row][col] == '.')
        return false;
    if(visited[row][col])
        return false;
    return true;
}

void BFS(int r, int c){
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));
    visited[r][c] = true;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol)){
                q.push(make_pair(nextRow,nextCol));
                visited[nextRow][nextCol] = true;
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--){
        cin >> ROW >> COL;

        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++)
                cin >> map[r][c];
        }

        memset(visited,false,sizeof(visited));

        int result = 0;
        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                if(map[r][c] == '#' &&  visited[r][c] == false){
                    BFS(r,c);
                    result++;
                }
            }
        }
        cout << result << '\n';

    } 
    return 0;
}