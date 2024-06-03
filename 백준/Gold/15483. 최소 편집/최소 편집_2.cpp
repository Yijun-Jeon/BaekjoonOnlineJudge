#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX_LEN 1000

using namespace std;

int dp[2][MAX_LEN+1];

int main(void)
{
    string a,b;
    cin >> a >> b;

    int N = a.size();
    int M = b.size();

    for(int j=0;j<=N;j++)
        dp[0][j] = j;

    for(int i=1;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(j == 0)
                dp[i&1][j] = dp[(i&1)^1][j] + 1;
            else if(a[j-1] == b[i-1])
                dp[i&1][j] = dp[(i&1)^1][j-1];
            else
                dp[i&1][j] = min(dp[(i&1)^1][j],min(dp[i&1][j-1],dp[(i&1)^1][j-1])) + 1;
        }
    }

    printf("%d\n",dp[M&1][N]);
    return 0;
}