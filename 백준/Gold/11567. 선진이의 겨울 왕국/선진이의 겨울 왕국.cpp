#include <iostream>
#include <queue>

#define MAX_N 500

using namespace std;

int N,M;
int r1,c1,r2,c2;
int map[MAX_N+1][MAX_N+1];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col){
    if(row <= 0 || row > N || col <= 0 || col > M)
        return false;
    if(row == r2 && col == c2)
        return true;
    if(map[row][col])
        return false;
    return true;
}

bool BFS(){
    queue<pair<int,int> > q;
    q.push(make_pair(r1,c1));
    map[r1][c1] = 0;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(row == r2 && col == c2){
            if(map[r2][c2] == 1) return true;
        }else if(map[row][col])
            continue;

        map[row][col]++;
        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol))
                q.push(make_pair(nextRow,nextCol));
        }
    }
    return false;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int n=1;n<=N;n++){
        for(int m=1;m<=M;m++){
            char c;
            cin >> c;

            if(c == 'X')
                map[n][m] = 1;
            else if(c == '.')
                map[n][m] = 0;
        }
    }

    cin >> r1 >> c1 >> r2 >> c2;

    if(BFS()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}