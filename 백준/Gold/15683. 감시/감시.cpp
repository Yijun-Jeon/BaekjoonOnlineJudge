#include <stdio.h>
#include <vector>
#include <cmath>

#define MAX_N 8

using namespace std;

int N,M, result = MAX_N*MAX_N;
int map[MAX_N][MAX_N];
vector<pair<int,pair<int,int> > > cameras;

int rows[6][5][5];
int cols[6][5][5];

void setCameraCases(){
    // camera 1
    rows[1][1][1] = 0;
    rows[1][2][1] = 1;
    rows[1][3][1] = 0;
    rows[1][4][1] = -1;

    cols[1][1][1] = 1;
    cols[1][2][1] = 0;
    cols[1][3][1] = -1;
    cols[1][4][1] = 0;

    //camera 2
    rows[2][1][1] = 0, rows[2][1][2] = 0;
    rows[2][2][1] = 1, rows[2][2][2] = -1;
    rows[2][3][1] = 0, rows[2][3][2] = 0;
    rows[2][4][1] = 1, rows[2][4][2] = -1;

    cols[2][1][1] = 1, cols[2][1][2] = -1;
    cols[2][2][1] = 0, cols[2][2][2] = 0;
    cols[2][3][1] = 1, cols[2][3][2] = -1;
    cols[2][4][1] = 0, cols[2][4][2] = 0;

    //camera 3
    rows[3][1][1] = -1, rows[3][1][2] = 0;
    rows[3][2][1] = 0, rows[3][2][2] = 1;
    rows[3][3][1] = 1, rows[3][3][2] = 0;
    rows[3][4][1] = 0, rows[3][4][2] = -1;

    cols[3][1][1] = 0, cols[3][1][2] = 1;
    cols[3][2][1] = 1, cols[3][2][2] = 0;
    cols[3][3][1] = 0, cols[3][3][2] = -1;
    cols[3][4][1] = -1, cols[3][4][2] = 0;

    //camera 4
    rows[4][1][1] = 0, rows[4][1][2] = -1,rows[4][1][3] = 0;
    rows[4][2][1] = -1,rows[4][2][2] = 0, rows[4][2][3] = 1;
    rows[4][3][1] = 0, rows[4][3][2] = 1, rows[4][3][3] = 0;
    rows[4][4][1] = 1, rows[4][4][2] = 0, rows[4][4][3] = -1;

    cols[4][1][1] = -1, cols[4][1][2] = 0, cols[4][1][3] = 1; 
    cols[4][2][1] = 0, cols[4][2][2] = 1, cols[4][2][3] = 0;
    cols[4][3][1] = 1, cols[4][3][2] = 0, cols[4][3][3] = -1;
    cols[4][4][1] = 0, cols[4][4][2] = -1, cols[4][4][3] = 0;

    //camera 5
    rows[5][1][1] = 0, rows[5][1][2] = -1,rows[5][1][3] = 0, rows[5][1][4] = 1;

    cols[5][1][1] = -1, cols[5][1][2] = 0,cols[5][1][3] = 1, cols[5][1][4] = 0;
}

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= M)
        return false;
    return true;
}

void DFS(int idx){
    if(idx == cameras.size()){
        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] == 0)
                    cnt++;
            }
        }
        result = min(result,cnt);
        return;
    } 

    
    int camera = cameras[idx].first;
    int row = cameras[idx].second.first;
    int col = cameras[idx].second.second;
    for(int i=1;i<=4;i++){
        vector<pair<int,int> > changed;
        for(int j=1;j<=4;j++){
            for(int k=1;k<=MAX_N;k++){
                int nextRow = row + rows[camera][i][j] * k;
                int nextCol = col + cols[camera][i][j] * k;
                if(checkPosValid(nextRow,nextCol)){
                    if(map[nextRow][nextCol] == 6)
                        break;
                    if(map[nextRow][nextCol] == 0){
                        changed.push_back(make_pair(nextRow,nextCol));
                        map[nextRow][nextCol] = camera;
                    }
                }
            }
        }

        DFS(idx+1);

        for(int c=0;c<changed.size();c++)
            map[changed[c].first][changed[c].second] = 0;
    }
    
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);

            if(1 <= map[i][j] && map[i][j] <= 5)
                cameras.push_back(make_pair(map[i][j],make_pair(i,j)));
        }
    }

    setCameraCases();

    DFS(0);

    printf("%d\n",result);
    return 0;
}
