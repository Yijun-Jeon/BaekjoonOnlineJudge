#include <stdio.h>
#include <algorithm>

#define MAX_N 300

using namespace std;

int stairs[MAX_N+1];

// dp[i][0] : 직전에 2칸 뜀
// dp[i][1] : 직전에 1칸 뜀
int dp[MAX_N][2];
int N;

int main(void)
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&stairs[i]);

	dp[1][0] = dp[1][1] = stairs[1];

	for(int i=2;i<=N;i++){
		dp[i][0] = max(dp[i-2][0],dp[i-2][1]) + stairs[i];
		dp[i][1] = dp[i-1][0] + stairs[i];
	}

	printf("%d\n",max(dp[N][0],dp[N][1]));
    return 0;
}