#include <stdio.h>
#include <queue>

#define MAX_N 5000

using namespace std;

int ROW,COL,cnt;

// 동/북/서/남
int rows[4] = {0,-1,0,1};
int cols[4] = {1,0,-1,0};

// dir : 동/남/서/북
void BFS(){
    int dir = 0;
    queue<pair<int,int> > q;
    q.push(make_pair(ROW-1,-1));

    int row = ROW-1;
    int col = COL;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(cnt == ROW * COL){
            printf("%d %d\n",c,ROW-r-1);
            return;
        }

        int nextRow = r + rows[dir] * row;
        int nextCol = c + cols[dir] * col;
        q.push(make_pair(nextRow,nextCol));
        dir = (dir+1)%4;

        if(dir % 2){
            cnt += col;
            col--;
        }
        else{
            cnt += row;
            row--;
        }
    }
}


int main(void)
{
    scanf("%d %d",&COL,&ROW);

    BFS();

    return 0;
}