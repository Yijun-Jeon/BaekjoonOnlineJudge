#include <stdio.h>
#include <queue>

#define MAX_W 50

using namespace std;

int COL,ROW;
int map[MAX_W][MAX_W];
bool visited[MAX_W][MAX_W];

int rows[8] = {-1,-1,-1,0,0,1,1,1};
int cols[8] = {-1,0,1,-1,1,-1,0,1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if(map[row][col] == 0)
        return false;
    if(visited[row][col])
        return false;
    return true;
}

void BFS(int r, int c){
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(visited[row][col])
            continue;
        visited[row][col] = true;

        for(int i=0;i<8;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol))
                q.push(make_pair(nextRow,nextCol));
        }
    }
}

int main(void)
{
    while(true){
        scanf("%d %d",&COL,&ROW);
        if(COL == 0 && ROW == 0)
            break;        

        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                scanf("%d",&map[i][j]);
                visited[i][j] = false;
            }
        }

        int result = 0;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(checkPosValid(i,j)){
                    BFS(i,j);
                    result++;
                }
            }
        }
        printf("%d\n",result);
    }
    return 0;
}