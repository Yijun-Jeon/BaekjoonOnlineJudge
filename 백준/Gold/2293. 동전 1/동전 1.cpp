#include <stdio.h>
#include <algorithm>

#define MAX_N 100
#define MAX_K 10000

using namespace std;

int coins[MAX_N];
int dp[2][MAX_K+1];
int n,k;


int main(void)
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&coins[i]);

	sort(coins,coins+n+1);

	dp[0][0] = dp[1][0] = 1;

	for(int i=1;i<=k;i++){
		if(i % coins[1] == 0)
			dp[0][i] = 1;
	}

	int lastIdx = 0;
	int nowIdx = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j >= coins[i])
				dp[nowIdx][j] = dp[lastIdx][j] + dp[nowIdx][j-coins[i]];
			else
				dp[nowIdx][j] = dp[lastIdx][j];
		}
		lastIdx ^= 1;
		nowIdx ^= 1;
	}

	printf("%d\n",dp[lastIdx][k]);
	return 0;
}