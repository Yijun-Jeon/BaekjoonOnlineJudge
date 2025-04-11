#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 1000
#define MAX_DIST 2e9

using namespace std;

int K,W,H,result;

int costs[26];
int dist[MAX_N][MAX_N];
char map[MAX_N][MAX_N];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

bool checkPosValid(int row, int col, int cost){
    if(row < 0 || row >= H  || col < 0 || col >= W)
        return false;
    if(map[row][col] == 'E')
        return false;
    if(dist[row][col] <= cost)
        return false;
    return true;
}

int BFS(int startRow, int startCol){
    fill(&dist[0][0],&dist[H-1][W],MAX_DIST);
    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(startRow,startCol)));
    dist[startRow][startCol] = 0;
    result = MAX_DIST;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if(row == 0 || col == 0 || row == H-1 || col == W-1)
            return cost;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            int nextCost = cost + costs[map[nextRow][nextCol] - 'A'];
            if(checkPosValid(nextRow,nextCol,nextCost)){
                pq.push(make_pair(-nextCost,make_pair(nextRow,nextCol)));
                dist[nextRow][nextCol] = nextCost;
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
        cin >> K >> W >> H;

        while(K--){
            char name;
            int cost;

            cin >> name >> cost;
            costs[name-'A'] = cost;
        }

        int startRow,startCol;
        for(int h=0;h<H;h++){
            for(int w=0;w<W;w++){
                cin >> map[h][w];

                if(map[h][w] == 'E'){
                    startRow = h;
                    startCol = w;
                }
            }
        }
        cout << BFS(startRow,startCol) << '\n';
    }
    return 0;
}