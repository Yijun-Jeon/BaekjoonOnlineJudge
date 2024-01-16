

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 100
#define MAX_DIST 1e9

using namespace std;

int map[MAX_N][MAX_N];
// row, col, dir
int visited[MAX_N][MAX_N][2];
int N,answer = MAX_DIST;

// 왼쪽이동, 오른쪽이동, 위쪽이동, 아래쪽이동, 좌상회전, 좌하회전, 우상회전, 우하회전
int rowsLR[8] = {0,0,-1,1,0,1,0,1};
int colsLR[8] = {-1,1,0,0,-1,-1,0,0};
int otherRowsLR[8] = {0,0,-1,1,-1,0,-1,0};
int otherColsLR[8] = {-2,0,-1,-1,-1,-1,0,0};
int turnRowsLR[8] = {0,0,0,0,-1,1,-1,1};
int turnColsLR[8] = {0,0,0,0,0,0,-1,-1};


// 위쪽이동, 아래쪽이동, 왼쪽이동, 오른쪽이동, 좌상회전, 좌하회전, 우상회전, 우하회전
int rowsUD[8] = {-1,1,0,0,-1,0,-1,0};
int colsUD[8] = {0,0,-1,1,0,0,1,1};
int otherRowsUD[8] = {-2,0,-1,-1,-1,0,-1,0};
int otherColsUD[8] = {0,0,-1,1,-1,-1,0,0};
int turnRowsUD[8] = {0,0,0,0,0,-1,0,-1};
int turnColsUD[8] = {0,0,0,0,-1,-1,1,1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= N)
        return false;
    if(map[row][col] == 1)
        return false;
    return true;
}

pair<pair<int,int>,int> moveOrRotate(int row, int col, int dir, int cnt, int i){
    int newRow,newCol,newDir;
    int otherRow,otherCol;
    int turnRow, turnCol;
    pair<pair<int,int>,int> result = {{-1,-1},-1};
    // 좌우
    if(dir == 0){
        newRow = row + rowsLR[i], newCol = col + colsLR[i];
        otherRow = row + otherRowsLR[i], otherCol = col + otherColsLR[i];
        turnRow = row + turnRowsLR[i], turnCol = col + turnColsLR[i];
        if(i==0){ // 왼쪽이동            
            if(!checkPosValid(otherRow,otherCol))
                return result; 
            newDir = 0;
        }else if(i==1){ // 오른쪽이동
            otherRow = row,otherCol = col;
            if(!checkPosValid(newRow,newCol))
                return result;
            newDir = 0;
        }else if(i==2){ // 위쪽이동
            if(!checkPosValid(newRow,newCol) || !checkPosValid(otherRow,otherCol))
                return result;
            newDir = 0;
        }else if(i==3){ // 아래쪽이동
            if(!checkPosValid(newRow,newCol) || !checkPosValid(otherRow,otherCol))
                return result;
            newDir = 0;
        }
        else if(i==4){ // 좌상회전
            if(!checkPosValid(otherRow,otherCol) || !checkPosValid(turnRow,turnCol))
                return result;
            newDir = 1;
        }else if(i==5){ // 좌하회전
            if(!checkPosValid(newRow,newCol) || !checkPosValid(turnRow,turnCol))
                return result;
            newDir = 1;
        }else if(i==6){ // 우상회전
            if(!checkPosValid(otherRow,otherCol) || !checkPosValid(turnRow,turnCol))
                return result;
            newDir = 1;
        }else if(i==7){ // 우하회전
            if(!checkPosValid(newRow,newCol) || !checkPosValid(turnRow,turnCol))
                return result;
            newDir = 1;
        }
        result = {{newRow,newCol},newDir};
    }
    // 상하
    else{
        newRow = row + rowsUD[i], newCol = col + colsUD[i];
        otherRow = row + otherRowsUD[i], otherCol = col + otherColsUD[i];
        turnRow = row + turnRowsUD[i], turnCol = col + turnColsUD[i];
        if(i == 0){ // 위쪽이동
            if(!checkPosValid(otherRow,otherCol))
                return result;
            newDir = 1;
        }else if(i==1){ // 아래쪽이동
            if(!checkPosValid(newRow,newCol))
                return result;
            newDir = 1;
        }else if(i==2){ // 왼쪽이동
            if(!checkPosValid(newRow,newCol) || !checkPosValid(otherRow,otherCol))
                return result;
            newDir = 1;
        }else if(i==3){ // 오른쪽이동
            if(!checkPosValid(newRow,newCol) || !checkPosValid(otherRow,otherCol))
                return result;
            newDir = 1;
        }
        else if(i==4){ // 좌상회전
            if(!checkPosValid(otherRow,otherCol) || !checkPosValid(turnRow,turnCol))
                return result;
            newDir = 0;
        }else if(i==5){ // 좌하회전
            if(!checkPosValid(otherRow,otherCol) || !checkPosValid(turnRow,turnCol))
                return result;
            newDir = 0;
        }else if(i==6){ // 우상회전
            if(!checkPosValid(newRow,newCol) || !checkPosValid(turnRow,turnCol))
                return result;
            newDir = 0;
        }else if(i==7){ // 우하회전
            if(!checkPosValid(newRow,newCol) || !checkPosValid(turnRow,turnCol))
                return result;
            newDir = 0;
        }
        result = {{newRow,newCol},newDir};
    }
    return result;
}

void BFS(){
    // row, col, dir, count
    // dir 0 : 좌우 -> 오른쪽이 기준 pos
    // dir 1 : 상하 -> 아래쪽이 기준 pos
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,1},{0,0}});

    int result = MAX_DIST;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
    
        if(cnt >= visited[row][col][dir])
            continue;
        
        visited[row][col][dir] = cnt;
        if(row == N-1 && col == N-1){
            continue;
        }
        
        for(int i=0;i<8;i++){
            pair<pair<int,int>,int> newPos = moveOrRotate(row,col,dir,cnt,i);
            int newRow = newPos.first.first;
            int newCol = newPos.first.second;
            int newDir = newPos.second;
            
            if(newRow != -1){
                q.push({{newRow,newCol},{newDir,cnt+1}});
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    N = board.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j] = board[i][j];
        }
    }
    fill(&visited[0][0][0],&visited[MAX_N-1][MAX_N-1][2],MAX_DIST);
    BFS();
    
    return min(visited[N-1][N-1][0],visited[N-1][N-1][1]); 
}
