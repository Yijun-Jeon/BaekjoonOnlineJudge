#include <stdio.h>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int N,M;
int dp[2][MAX_N][4]; // 1: 아래, 2: -> , 3: <-

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++)
            scanf("%d",&dp[n%2][m][0]);

        if(n == 0){
            dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = dp[0][0][0];
            for(int m=1;m<M;m++)
                dp[0][m][1] = dp[0][m][2] = dp[0][m][3] = dp[0][m][0] + dp[0][m-1][1];
            continue;
        }

        for(int m=0;m<M;m++){
            // 아래
            dp[n%2][m][1] = dp[n%2][m][0] + max(dp[(n-1)%2][m][1],max(dp[(n-1)%2][m][2],dp[(n-1)%2][m][3]));

            // ->
            if(m == 0) dp[n%2][0][2] = dp[n%2][0][1];
            else dp[n%2][m][2] = dp[n%2][m][0] + max(dp[n%2][m-1][1],dp[n%2][m-1][2]);
        }

        // <-
        for(int m=M-1;m>=0;m--){
            if(m == M-1) dp[n%2][m][3] = dp[n%2][m][1];
            else dp[n%2][m][3] = dp[n%2][m][0] + max(dp[n%2][m+1][1],dp[n%2][m+1][3]);
        }
    }

    printf("%d\n",max(dp[(N-1)%2][M-1][1],dp[(N-1)%2][M-1][2]));
    return 0;
}