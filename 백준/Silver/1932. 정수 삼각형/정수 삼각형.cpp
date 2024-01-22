#include <stdio.h>
#include <algorithm>

#define MAX_N 500

using namespace std;

int dp[MAX_N+1][MAX_N+1];
int n;

int main(void)
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            scanf("%d",&dp[i][j]);
    }

    int result = dp[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + dp[i][j];
            result = max(result,dp[i][j]);
        }
    }
    printf("%d\n",result);
    return 0;
}