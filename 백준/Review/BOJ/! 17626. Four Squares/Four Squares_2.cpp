#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX_N 50000

using namespace std;

int dp[MAX_N+1];

int main(void)
{
    int n;
    scanf("%d",&n);

    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = 4;
        for(int j=1;j*j<=i;j++)
            dp[i] = min(dp[i],dp[i-j*j]+1);
    }

    printf("%d\n",dp[n]);
    return 0;
}
