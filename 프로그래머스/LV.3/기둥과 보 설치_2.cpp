#include <string>
#include <vector>

#define MAX_N 100

using namespace std;

int map[MAX_N+1][MAX_N+1];
int N;

bool checkPosValid(int x, int y){
    if(x < 0 || x > N || y < 0 || y > N)
        return false;
    return true;
}

bool checkIsValid(){
    for(int row=0;row<=N;row++){
        for(int col=0;col<=N;col++){
            if(map[row][col] == 0)
                continue;
            
            bool valid = false;
            // 위로 기둥
            if(((map[row][col] >> 1) & 1)){
                // 바닥 위
                if(row == 0)
                    valid = true;
                // 기둥 위
                if(checkPosValid(row-1,col) && ((map[row-1][col] >> 1) & 1))
                    valid = true;
                // 오른쪽 보 위
                if((map[row][col] & 1))
                    valid = true;
                // 왼쪽 보 위
                if(checkPosValid(row,col-1) && (map[row][col-1] & 1))
                    valid = true;
                
                if(valid == false)
                    return false;
            }
            valid = false;
            // 오른쪽 보
            if((map[row][col] & 1)){
                // 왼쪽이 기둥 위
                if(checkPosValid(row-1,col) && ((map[row-1][col] >> 1) & 1))
                    valid = true;
                // 오른쪽이 기둥 위
                if(checkPosValid(row-1,col+1) && ((map[row-1][col+1] >> 1) & 1))
                    valid = true;
                // 양쪽이 보
                if(checkPosValid(row,col-1) && (map[row][col-1] & 1)){
                    if(checkPosValid(row,col+1) && (map[row][col+1] & 1))
                        valid = true;
                }
                if(valid == false)
                    return false;
            }            
        }
    }
    return true;
}

void work(int row, int col, int a, int b){
    // 구조물 삭제
    if(b == 0){
        // 기둥 삭제
        if(a == 0){
            map[row][col] ^= (1 << 1);
            if(checkIsValid() == false)
                map[row][col] |= (1 << 1);
        }
        // 보 삭제
        else if(a == 1){
             map[row][col] ^= 1;
            if(checkIsValid() == false)
                map[row][col] |= 1;
        }
    }
    // 구조물 설치
    else if(b == 1){
        // 기둥 설치
        if(a == 0){
            map[row][col] |= (1 << 1);
            if(checkIsValid() == false)
                map[row][col] ^= (1 << 1);
        }
        // 보 설치
        else if(a == 1){
            map[row][col] |= 1;
            if(checkIsValid() == false)
                map[row][col] ^= 1;
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    N = n;
    for(auto build : build_frame){
        int col = build[0];
        int row = build[1];
        int a = build[2];
        int b = build[3];
        
        work(row,col,a,b);
    }
    
    for(int col=0;col<=N;col++){
        for(int row=0;row<=N;row++){
            if(((map[row][col] >> 1) & 1))
                answer.push_back({col,row,0});
            if((map[row][col] & 1))
                answer.push_back({col,row,1});
        }
    }
    return answer;
}