#include <stdio.h>
#include <algorithm>

#define MAX_N 15

using namespace std;

int dp[MAX_N+1][MAX_N+2];
int times[MAX_N+1];

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=1;i<=N;i++){
        scanf("%d",&times[i]);
        scanf("%d",&dp[i][0]);
    }

    for(int i=1;i<=N;i++){
        int time = i + times[i];
        for(int j=1;j<=N+1;j++){
            if(j < time)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][i] + dp[i][0]);
        }
    }
    
    printf("%d\n",dp[N][N+1]);
    return 0;
}