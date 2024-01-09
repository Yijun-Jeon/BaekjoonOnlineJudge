#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 6

using namespace std;

// X , T , S , O
int map[MAX_N][MAX_N];
int N;

vector<pair<int,int> > emptyVec;
vector<pair<int,int> > teachers;
int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,1,-1};

bool isSafe(){
    // 모든 선생님들의 상,하,좌,우 돌면서 검사
    for(int i=0;i<(int)teachers.size();i++){
        int row = teachers[i].first;
        int col = teachers[i].second;

        for(int j=0;j<4;j++){
            int mul = 1;
            while(true){
                int nextRow = row + rows[j] * mul;
                int nextCol = col + cols[j] * mul++;

                if(nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N)
                    break;

                if(map[nextRow][nextCol] == 3)
                    break;

                if(map[nextRow][nextCol] == 2)
                    return false;
            }
        }
    }

    return true;
}

int main(void)
{   
    scanf("%d ",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<=2*(N-1)+1;j++){
            char temp;
            scanf("%c",&temp);

            if(j % 2 == 1)
                continue;

            if(temp == 'X'){
                map[i][j/2] = 0;
                emptyVec.push_back(make_pair(i,j/2));
            }else if(temp == 'T'){
                map[i][j/2] = 1;
                teachers.push_back(make_pair(i,j/2));
            }else if(temp == 'S'){
                map[i][j/2] = 2;
            }
        }
    }

    // 조합용 벡터
    vector<int> tempVec;
    for(int i=0;i<3;i++)
        tempVec.push_back(0);
    for(int i=0;i<(int)emptyVec.size()-3;i++)
        tempVec.push_back(1);
    
    bool result = false;
    do{
        // 장애물 설치
        for(int i=0;i<(int)tempVec.size();i++){
            if(tempVec[i] == 0)
                map[emptyVec[i].first][emptyVec[i].second] = 3;
        }

        if(isSafe()){
            result = true;
            break;
        }

        // 장애물 제거
        for(int i=0;i<(int)tempVec.size();i++){
            if(tempVec[i] == 0)
                map[emptyVec[i].first][emptyVec[i].second] = 0;
        }

    }while(next_permutation(tempVec.begin(),tempVec.end()));

    if(result) printf("%s\n","YES");
    else printf("%s\n","NO");

    return 0;
}