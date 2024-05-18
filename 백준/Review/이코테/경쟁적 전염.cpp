#include <stdio.h>
#include <queue>

#define MAX_N 200

using namespace std;

int map[MAX_N+1][MAX_N+1];
int N,K;
int S,X,Y;

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,1,-1};

priority_queue<pair<int,pair<int,pair<int,int> > > > pq;

bool checkPosValid(int row, int col){
    if(row < 1 || row > N || col < 1 || col > N)
        return false;
    if(map[row][col] != 0)
        return false;
    return true;
}

void BFS(){
    while(!pq.empty()){
        int time = -pq.top().first;
        if(time > S)
            break;

        int num = -pq.top().second.first;
        int row = pq.top().second.second.first;
        int col = pq.top().second.second.second;
        pq.pop();

        if(time > 0 && map[row][col] != 0)
            continue;

        map[row][col] = num;
        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol))
                pq.push(make_pair(-time-1,make_pair(-num,make_pair(nextRow,nextCol))));
        }
    }
}

int main(void)
{
    scanf("%d %d",&N,&K);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&map[i][j]);

            if(map[i][j] != 0){
                pq.push(make_pair(0,make_pair(-map[i][j],make_pair(i,j))));
            }
        }
    }

    scanf("%d %d %d",&S,&X,&Y);
    BFS();

    printf("%d\n",map[X][Y]);
    return 0;
}