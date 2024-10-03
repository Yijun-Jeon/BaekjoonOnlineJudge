#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    scanf("%d",&N);

    int dp[N+1];

    dp[0] = 0;
    for(int i=1;i<=N;i++){
        dp[i] = 4;
        for(int j=1;j*j<=i;j++)
            dp[i] = min(dp[i],dp[i-j*j]+1);
    }
    printf("%d\n",dp[N]);
    return 0;
}