#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define MAX_DIST 10000

using namespace std;

int map[MAX_N+1][MAX_N+1];
int dist[MAX_N+1][MAX_N+1][2];
int N;

// 가로 방향 head 선택지
// 상, 하, 우, 좌, 상우, 상좌, 하우, 하좌
int rowsH[8] = {-1,1,0,0,0,0,1,1};
int colsH[8] = {0,0,1,-1,0,-1,0,-1};
// 가로 방향 head - tail / row,col
int tailH[2] = {0,-1};
// 회전 pos
// 상, 하, 우, 좌, 상우, 상좌, 하우, 하좌
int rowsH2V[8] = {0,0,0,0,-1,-1,1,1};
int colsH2V[8] = {0,0,0,0,-1,0,-1,0};

// 세로 방향 head 선택지
// 상, 하, 우, 좌, 상우, 상좌, 하우, 하좌
int rowsV[8] = {-1,1,0,0,-1,-1,0,0};
int colsV[8] = {0,0,1,-1,1,0,1,0};
// 세로 방향 head - tail / row,col
int tailV[2] = {-1,0};
// 회전 pos
// 상, 하, 우, 좌, 상우, 상좌, 하우, 하좌
int rowsV2H[8] = {0,0,0,0,0,0,-1,-1};
int colsV2H[8] = {0,0,0,0,1,-1,1,-1};

bool checkPosValid(int row, int col,int dir,bool rotate){
    if(rotate == false){ 
        int tailRow;
        int tailCol;
        if(dir == 0){
            tailRow = row + tailH[0];
            tailCol = col + tailH[1];
        }else if(dir == 1){
            tailRow = row + tailV[0];
            tailCol = col + tailV[1];
        }
        if(tailRow <= 0 || tailRow > N || tailCol <= 0 || tailCol > N)
            return false; 
        if(map[tailRow][tailCol] == 1)
            return false;
    }
    if(row <= 0 || row > N || col <= 0 || col > N)
        return false;
    if(map[row][col] == 1)
        return false;
    return true;
}

// dir : 0-가로 1-세로
void DFS(int dir, int row, int col, int time){
    if(time >= min(dist[N][N][0],dist[N][N][1]))
        return;
    
    if(time >= dist[row][col][dir])
        return;
    
    dist[row][col][dir] = time;
    
    for(int i=0;i<8;i++){
        // 가로
        if(dir == 0){
            // head
            int nextRow = row + rowsH[i];
            int nextCol = col + colsH[i];
            
            // rotatePos
            int rotateRow = row + rowsH2V[i];
            int rotateCol = col + colsH2V[i];
        
            if(i<4){
                if(checkPosValid(nextRow,nextCol,dir,false)){
                    if(dist[nextRow][nextCol][dir] > time+1)
                        DFS(dir,nextRow,nextCol,time+1);
                }
            }else{
                if(checkPosValid(nextRow,nextCol,dir^1,false) && checkPosValid(rotateRow,rotateCol,dir,true)){
                    if(dist[nextRow][nextCol][dir^1] > time+1)
                        DFS(dir^1,nextRow,nextCol,time+1);   
                }
            }
        }
        // 세로
        else{
            // head
            int nextRow = row + rowsV[i];
            int nextCol = col + colsV[i];
            
            // rotatePos
            int rotateRow = row + rowsV2H[i];
            int rotateCol = col + colsV2H[i];
        
            if(i<4){
                if(checkPosValid(nextRow,nextCol,dir,false)){
                    if(dist[nextRow][nextCol][dir] > time+1)
                        DFS(dir,nextRow,nextCol,time+1);
                }   
            }else{
                if(checkPosValid(nextRow,nextCol,dir^1,false) && checkPosValid(rotateRow,rotateCol,dir,true)){
                    if(dist[nextRow][nextCol][dir^1] > time+1)
                        DFS(dir^1,nextRow,nextCol,time+1);   
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    N = board.size();
    
    for(int i=1;i<=board.size();i++){
        for(int j=1;j<=board[0].size();j++){
            map[i][j] = board[i-1][j-1];
        }
    }
    
    fill(&dist[1][1][0],&dist[N+1][0][0],MAX_DIST);
    
    DFS(0,1,2,0);
    
    return min(dist[N][N][0],dist[N][N][1]);
}