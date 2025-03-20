#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 100
#define MAX_DIST 10000

using namespace std;

int N,M;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col, int dist){
    if(row < 0 || row >= M || col < 0 || col >= N)
        return false;
    if(visited[row][col] <= dist)
        return false;
    return true;
}

void BFS(){
    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(0,0)));

    while(!pq.empty()){
        int dist = -pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if(visited[row][col] <= dist)
            continue;
        visited[row][col] = dist;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            int nextDist = map[nextRow][nextCol] ? dist+1 : dist;
            if(checkPosValid(nextRow,nextCol,nextDist))
                pq.push(make_pair(-nextDist,make_pair(nextRow,nextCol)));
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    fill(&visited[0][0], &visited[M-1][N], MAX_DIST);
    for(int i=0;i<M;i++){
        string line;
        cin >> line;

        for(int j=0;j<N;j++)
            map[i][j] = line[j] - '0';
    }

    BFS();

    cout << visited[M-1][N-1] << '\n';
    return 0;
}
