#include <stdio.h>
#include <algorithm>

#define MAX_N 500

using namespace std;

int N,M;
int map[MAX_N][MAX_N];

int rows[19][4] = {
    0,0,0,0,
    0,1,2,3,
    0,0,1,1,
    0,1,2,2,
    0,0,0,1,
    0,0,1,2,
    0,0,0,-1,
    0,0,-1,-2,
    0,1,1,1,
    0,0,1,2,
    0,0,0,1,
    0,1,1,2,
    0,1,-1,0,
    0,0,-1,-1,
    0,0,1,1,
    0,0,0,1,
    0,-1,0,1,
    0,-1,0,0,
    0,1,2,1
};

int cols[19][4] = {
    0,1,2,3,
    0,0,0,0,
    0,1,0,1,
    0,0,0,1,
    0,1,2,0,
    0,1,1,1,
    0,1,2,2,
    0,1,1,1,
    0,0,1,2,
    0,1,0,0,
    0,1,2,2,
    0,0,1,1,
    0,0,1,1,
    0,1,1,2,
    0,1,1,2,
    0,1,2,1,
    0,1,1,1,
    0,1,1,2,
    0,0,0,1
};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= M)
        return false;
    return true;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            scanf("%d",&map[i][j]);
    }

    int result = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int p=0;p<19;p++){
                int tetromino = 0;
                bool valid = true;
                for(int k=0;k<4;k++){
                    int row = i + rows[p][k];
                    int col = j + cols[p][k];

                    valid = checkPosValid(row,col);
                    if(valid == false) break;

                    tetromino += map[row][col];
                }
                if(valid) result = max(result,tetromino);
            }
        }
    }

    printf("%d\n",result);
    return 0;
}