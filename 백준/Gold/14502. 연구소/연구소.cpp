#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 8

using namespace std;

int map[MAX_N][MAX_N];
int tempMap[MAX_N][MAX_N];

int N,M;
vector<pair<int,int> > zeroVec;

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,1,-1};

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= M)
        return false;
    if(tempMap[row][col] >= 1)
        return false;
    return true;
}

void BFS(int row, int col){
    queue<pair<int,int> > q;
    q.push(make_pair(row,col));
    tempMap[row][col] = 0;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(tempMap[r][c] == 2)
            continue;
        
        tempMap[r][c] = 2;
        for(int i=0;i<4;i++){
            int nextRow = r + rows[i];
            int nextCol = c + cols[i];
            if(checkPosValid(nextRow,nextCol))
                q.push(make_pair(nextRow,nextCol));
        }
    }
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);

            if(map[i][j] == 0)
                zeroVec.push_back(make_pair(i,j));

            tempMap[i][j] = map[i][j];
        }
    }

    // 조합을 위한 임시 벡터
    vector<int> tempVec;
    for(int i=0;i<zeroVec.size()-3;i++)
        tempVec.push_back(0);
    for(int i=0;i<3;i++)
        tempVec.push_back(1);
    

    int result = 0;
    do{
        // 벽 설치
        for(int i=0;i<tempVec.size();i++){
            if(tempVec[i] == 1){
                tempMap[zeroVec[i].first][zeroVec[i].second] = 1;
            }
        }

        // 바이러스 전파
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(tempMap[i][j] == 2)
                    BFS(i,j);
            }
        }

        int safe = 0;
        // 안전 영역 최대 크기 갱신  
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(tempMap[i][j] == 0)
                    safe++;
            }
        }
        result = max(result,safe);

        // 원래 맵으로 복귀
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                tempMap[i][j] = map[i][j];
        }

    } while(next_permutation(tempVec.begin(),tempVec.end()));

    printf("%d\n",result);
    return 0;
}
