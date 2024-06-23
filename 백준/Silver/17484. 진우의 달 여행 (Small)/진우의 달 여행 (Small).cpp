#include <stdio.h>
#include <algorithm>

#define MAX_N 6
#define MAX_COST 600

using namespace std;

// 0 : 연료,  1 : 좌상, 2 : 상, 3 : 우상
int map[MAX_N+1][MAX_N+2][4];
int N,M;

int main(void)
{
    fill(&map[0][0][0],&map[MAX_N][MAX_N+1][4],MAX_COST);

    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            scanf("%d",&map[i][j][0]);
    }

    for(int i=1;i<=M;i++)
        map[1][i][1] = map[1][i][2] = map[1][i][3] = map[1][i][0];

    int result = MAX_COST;
    for(int i=2;i<=N;i++){
        for(int j=1;j<=M;j++){
            map[i][j][1] = min(map[i-1][j-1][2],map[i-1][j-1][3]) + map[i][j][0];
            map[i][j][2] = min(map[i-1][j][1],map[i-1][j][3]) + map[i][j][0];
            map[i][j][3] = min(map[i-1][j+1][1],map[i-1][j+1][2]) + map[i][j][0];

            if(i == N)
                result = min(result,min(map[i][j][1],min(map[i][j][2],map[i][j][3])));
        }
    }

    printf("%d\n",result);
    return 0;
}

