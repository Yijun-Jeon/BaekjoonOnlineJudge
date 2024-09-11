#include <stdio.h>
#include <algorithm>

#define MAX_N 1000
#define MIN_COST -1e9

using namespace std;

int dp[2][MAX_N][4];
int N,M;

int main(void)
{
    scanf("%d %d",&N,&M);

    int map[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            scanf("%d",&map[i][j]);
    }

    dp[0][0][3] = map[0][0];
    for(int i=1;i<M;i++)
        dp[0][i][3] = dp[0][i-1][3] + map[0][i];

    for(int i=1;i<N;i++){
        int row = i%2;
        // 아래
        for(int j=0;j<M;j++){
            dp[row][j][0] = dp[row^1][j][3] + map[i][j];
            dp[row][j][3] = MIN_COST;
        }

        dp[row][M-1][1] = dp[row][M-1][0];
        dp[row][0][2] = dp[row][0][0];

        // 왼쪽
        for(int j=M-2;j>=0;j--)
            dp[row][j][1] = max(dp[row][j+1][1],dp[row][j+1][0]) + map[i][j];

        // 오른쪽
        for(int j=1;j<M;j++)
            dp[row][j][2] = max(dp[row][j-1][2],dp[row][j-1][0]) + map[i][j];

        // 최댓값
        for(int j=0;j<M;j++){
            for(int k=0;k<3;k++)
                dp[row][j][3] = max(dp[row][j][3],dp[row][j][k]);
        }
    }

    printf("%d\n",dp[(N-1)%2][M-1][3]);
    return 0;
}