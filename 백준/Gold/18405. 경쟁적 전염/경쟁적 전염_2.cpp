#include <stdio.h>
#include <queue>

#define MAX_N 200

using namespace std;

int map[MAX_N+1][MAX_N+1];
int N,K;
int S,X,Y;

int rows[4] = {1,-1,0,0};
int cols[4] = {0,0,1,-1};

priority_queue<pair<int,pair<int,pair<int,int> > > > pq;
queue<pair<int,pair<int,pair<int,int> > > > q;

bool checkPosValid(int row, int col){
    if(row <= 0 || row > N || col <= 0 || col > N)
        return false;
    if(map[row][col])
        return false;
    return true;
}

void BFS(){
    while(!q.empty()){
        int time = -q.front().first;
        int num = -q.front().second.first;
        int row = q.front().second.second.first;
        int col = q.front().second.second.second;
        q.pop();

        if(time >= S)
            break;

        if(map[row][col])
            continue;

        map[row][col] = num;
        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol))
                q.push(make_pair(-(time+1),make_pair(-num,make_pair(nextRow,nextCol))));
        }
    }
}

int main(void)
{
    scanf("%d %d",&N,&K);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int num;
            scanf("%d",&num);

            if(num) pq.push(make_pair(0,make_pair(-num,make_pair(i,j))));
        }
    }

    while(!pq.empty()){
        q.push(pq.top());
        pq.pop();
    }

    
    scanf("%d %d %d",&S,&X,&Y);
    S++;

    BFS();

    printf("%d\n",map[X][Y]);
    return 0;
}