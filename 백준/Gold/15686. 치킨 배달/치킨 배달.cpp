#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAX_N 50
#define MAX_M 13
#define MAX_DIST 1e9

using namespace std;

int map[MAX_N+1][MAX_N+1];
int dist[2*MAX_N][MAX_M];
int N,M;
int totalChicken = 0;
int totalCity = 0;
int result = MAX_DIST;

void DFS(int idx, int chickenSum, vector<int> choosenDist[]){
    if(chickenSum == M){
        int distSum = 0;
        for(int i=0;i<totalCity;i++)
            distSum += *min_element(choosenDist[i].begin(),choosenDist[i].end());

        result = min(result,distSum);
        return;
    }

    if(idx >= totalChicken)
        return;

    DFS(idx+1,chickenSum,choosenDist);

    for(int i=0;i<totalCity;i++)
        choosenDist[i].push_back(dist[i][idx]);
    
    DFS(idx+1,chickenSum+1,choosenDist);
    for(int i=0;i<totalCity;i++)
        choosenDist[i].pop_back();
    
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2)
                totalChicken++;
            if(map[i][j] == 1)
                totalCity++;
        }
    }

    int city = 0;
    // 각 집에서 모든 치킨집까지 거리 저장
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j] == 1){
                int chiken = 0;
                for(int r=1;r<=N;r++){
                    for(int c=1; c<=N;c++){
                        if(map[r][c] == 2){
                            dist[city][chiken++] = abs(r-i) + abs(c-j);
                        }
                    }
                }    
                city++;
            }
        }
    }

    vector<int> choosenDist[totalCity];
    // M개의 치킨집 최소 도시거리
    DFS(0,0,choosenDist);
    printf("%d\n",result);
    return 0;
}