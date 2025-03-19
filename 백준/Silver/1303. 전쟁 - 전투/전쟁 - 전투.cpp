#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100

using namespace std;

int N,M;
bool visited[MAX_N][MAX_N];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

vector<string> map;

bool checkPosValid(int row, int col, char color){
    if(row < 0 || row >= M || col < 0 || col >= N)
        return false;
    if(visited[row][col])
        return false;
    return map[row][col] == color;
}

int BFS(int r, int c){
    char color = map[r][c];
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));

    int power = 0;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(visited[row][col])
            continue;
        visited[row][col] = true;
        power++;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol,color))
                q.push(make_pair(nextRow,nextCol));
        }
    }
    return power * power;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0;i<M;i++){
        string line;
        cin >> line;

        map.push_back(line);
    }

    int we = 0, other = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] == false){
                if(map[i][j] == 'W')
                    we += BFS(i,j);
                else
                    other += BFS(i,j);
            }
        }
    }
    cout << we << " " << other << '\n';
    return 0;
}
