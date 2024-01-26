#include <stdio.h>
#include <algorithm>

#define MAX_N 2000
#define MAX_POWER 1e7

using namespace std;

// 0 : power, 1 : include, 2 : except
int dp[MAX_N+1][3];
int N;

int main(void)
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&dp[i][0]);

    dp[0][0] = MAX_POWER;

    int result = 0;
    for(int i=1;i<=N;i++){
        // include
        for(int j=i-1;j>=0;j--){
            if(dp[i][0] < dp[j][0])
                dp[i][1] = max(dp[i][1],dp[j][1] + 1);
        }

        // exclude
        for(int j=i-1;j>=0;j--){
            dp[i][2] = max(dp[i][2],max(dp[j][1],dp[j][2]));
        }
    }
    
    printf("%d\n",N - max(dp[N][2],dp[N][1]));
    return 0;
}
