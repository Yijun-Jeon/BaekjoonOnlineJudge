#include <stdio.h>
#include <cstring>
#include <queue>
#include <cmath>

#define MAX_N 50

using namespace std;

int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int N,R,L;

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,1,-1};

bool checkPosValid(int row, int col, int prev){
    if(row < 0 || row >= N || col < 0 || col >= N)
        return false;
    if(visited[row][col])
        return false;
    if(abs(prev - map[row][col]) < L)
        return false;
    if(abs(prev - map[row][col]) > R)
        return false;
    return true;
}

bool BFS(int startRow, int startCol){
    queue<pair<int,int> > inQ;
    queue<pair<int,int> > outQ;
    inQ.push(make_pair(startRow,startCol));

    int sum = 0;
    while(!inQ.empty()){
        int row = inQ.front().first;
        int col = inQ.front().second;
        inQ.pop();

        if(visited[row][col])
            continue;

        sum += map[row][col];
        visited[row][col] = true;
        outQ.push(make_pair(row,col));

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol,map[row][col]))
                inQ.push(make_pair(nextRow,nextCol));
        }
    }

    int total = outQ.size();
    while(!outQ.empty()){
        int row = outQ.front().first;
        int col = outQ.front().second;
        outQ.pop();

        map[row][col] = sum/total;
    }

    return total > 1;
}

bool move(){
    memset(visited,false,sizeof(visited));

    bool moved = false;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] == false){
                moved |= BFS(i,j);
            }
        }
    }

    return moved;
}

int main(void)
{
    scanf("%d %d %d",&N,&L,&R);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            scanf("%d",&map[i][j]);
    }

    int result = 0;
    while(move()){
        result++;
    }

    printf("%d\n",result);
    return 0;
}
