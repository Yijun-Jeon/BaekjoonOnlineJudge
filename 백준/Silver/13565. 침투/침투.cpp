#include <iostream>
#include <queue>

#define MAX_N 1000

using namespace std;

int ROW,COL;
char map[MAX_N][MAX_N];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if(map[row][col] == '1')
        return false;
    return true;
}

bool BFS(int r, int c){
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));
    map[r][c] = '1';

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(row == ROW-1)
            return true;
        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol)){
                q.push(make_pair(nextRow,nextCol));
                map[nextRow][nextCol] = '1';
            }
        }
    }
    return false;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> ROW >> COL;
    for(int r=0;r<ROW;r++){
        for(int c=0;c<COL;c++){
            cin >> map[r][c];
        }
    }

    bool result = false;
    for(int c=0;c<COL && !result;c++){
        if(map[0][c] == '0'){
            result = BFS(0,c);
        }         
    }
    if(result) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}