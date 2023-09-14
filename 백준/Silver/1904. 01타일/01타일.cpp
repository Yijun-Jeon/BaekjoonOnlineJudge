#include <stdio.h>

#define MAX_N 1000000
#define MOD 15746

using namespace std;

int dp[MAX_N+1];

int fib(int N){
	dp[1] = 1;
	dp[2] = 2;

	for(int i=3;i<=N;i++){
		dp[i] = dp[i-1] % MOD + dp[i-2] % MOD;
		dp[i] %= MOD;
	}

	return dp[N];
}

int main(void)
{
	int N;
	scanf("%d",&N);

	printf("%d\n",fib(N));
    return 0;
}