#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

// 0b1000 : 위로 기둥, 0b0100 : 아래로 기둥, 0b0010 : 오른쪽 보, 0b0001 : 왼쪽 보
int map[MAX_N+1][MAX_N+1];
vector<vector<int>> answer;

bool checkWorkValid(){
    for(int i=0;i<answer.size();i++){
        int x = answer[i][0], y = answer[i][1], a = answer[i][2];
        
        // 기둥
        if(a == 0){
            if(y > 0 && map[y][x] - 0b1000 == 0)
                return false;
        }
        // 보
        else{
            if(((map[y][x] >> 2) & 1) || ((map[y][x+1] >> 2) & 1))
                continue;
            else if((map[y][x] & 1) && ((map[y][x+1] >> 1) & 1))
                continue;
            else 
                return false;
        }
    }
    return true;
}

void work(int x, int y, int a, int b){
    // 삭제
    if(b == 0){
        // 기둥
        if(a == 0){
            map[y][x] ^= 0b1000;
            map[y+1][x] ^= 0b0100;
        }
        // 보
        else{
            map[y][x] ^= 0b0010;
            map[y][x+1] ^= 0b0001;
        }
    }
    // 설치
    else{
        // 기둥
        if(a == 0){
            map[y][x] |= 0b1000;
            map[y+1][x] |= 0b0100;
        }
        // 보
        else{
            map[y][x] |= 0b0010;
            map[y][x+1] |= 0b0001;
        }   
    }
}

void check(int x,int y, int a, int b){
    // 삭제
    if(b == 0){
        work(x,y,a,b);
            
        for(auto iter = answer.begin(); iter != answer.end(); iter++){
            if((*iter)[0] == x && (*iter)[1] == y && (*iter)[2] == a){
                answer.erase(iter);
                break;
            }   
        }
        if(!checkWorkValid()){
            vector<int> temp = {x,y,a};
            answer.push_back(temp);
            
            work(x,y,a,b^1);
        }
    }
    // 설치
    else{
        vector<int> temp = {x,y,a};
        answer.push_back(temp);
        
        work(x,y,a,b);
        
        if(!checkWorkValid()){
            answer.pop_back();
            work(x,y,a,1^b);
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0],y = build_frame[i][1],
        a = build_frame[i][2],b = build_frame[i][3];
        
        check(x,y,a,b);
    }
    sort(answer.begin(),answer.end());
    return answer;
}