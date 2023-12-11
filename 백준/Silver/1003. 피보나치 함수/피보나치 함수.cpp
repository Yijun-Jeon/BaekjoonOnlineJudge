#include <iostream>
#include <stdio.h>

#define MAX_N 40

using namespace std;

int dp[MAX_N+1][2];

int main(void)
{
	int T;
	scanf("%d",&T);

	dp[0][0] = dp[1][1] = 1;

	for(int i=2;i<=MAX_N;i++){
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}

	for(int i=0;i<T;i++){
		int N;
		scanf("%d",&N);
		printf("%d %d\n",dp[N][0],dp[N][1]);
	}
    return 0;
}