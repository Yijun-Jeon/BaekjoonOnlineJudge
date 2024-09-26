#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_N 100

using namespace std;

int ROW,COL,K;
bool map[MAX_N][MAX_N];

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if(map[row][col])
        return false;
    return true;
}

int BFS(int r, int c){
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));

    int cnt = 0;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(map[row][col])
            continue;
        map[row][col] = true;
        cnt++;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol))
                q.push(make_pair(nextRow,nextCol));
        }
    }
    return cnt;
}

int main(void)
{
    scanf("%d %d %d",&ROW,&COL,&K);
    for(int k=0;k<K;k++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);

        for(int x=x1;x<x2;x++){
            for(int y=y1;y<y2;y++){
                map[x][y] = true;   
            }
        }
    }

    vector<int> result;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(checkPosValid(i,j))
                result.push_back(BFS(i,j));
        }
    }

    sort(result.begin(),result.end());
    printf("%d\n",(int)result.size());
    for(int i=0;i<result.size();i++)
        printf("%d ",result[i]);
    printf("\n");
    return 0;
}