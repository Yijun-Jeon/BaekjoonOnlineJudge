#include <iostream>
#include <cstring>
#include <queue>

#define MAX_N 15
#define MAX_DIST MAX_N * MAX_N

using namespace std;

int ROW,COL;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if(map[row][col] == 'X')
        return false;
    if(visited[row][col])
        return false;
    return true;
}

int BFS(int r, int c){
    priority_queue<pair<int,pair<int,int> > > q;
    q.push(make_pair(0,make_pair(r,c)));
    visited[r][c] = true;

    while(!q.empty()){
        int d = -q.top().first;
        int row = q.top().second.first;
        int col = q.top().second.second;
        q.pop();

        if(map[row][col] == 'G')
            return d;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol)){
                q.push(make_pair(-d-1,make_pair(nextRow,nextCol)));
                visited[nextRow][nextCol] = true;
            }
        }
    }

    return -1;
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

        int startRow,startCol;
        int endRow,endCol;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                cin >> map[i][j];

                if(map[i][j] == 'S'){
                    startRow = i;
                    startCol = j;
                }
            }
        }

        memset(visited,false,sizeof(visited));

        int result = BFS(startRow,startCol);
        if(result == -1)
            cout << "No Exit" << '\n';
        else
            cout << "Shortest Path: " << result << '\n';
    }

    return 0;
}