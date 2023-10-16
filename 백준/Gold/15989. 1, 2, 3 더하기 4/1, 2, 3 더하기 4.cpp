#include <stdio.h>

#define MAX_N 10000
#define MAX_VAL 3

using namespace std;

int nums[MAX_VAL] = {1,2,3};
int dp[MAX_VAL][MAX_N+1];
int n;

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int test_case=0;test_case<T;test_case++){
		scanf("%d",&n);

		for(int i=0;i<=n;i++)
			dp[0][i] = 1;

		dp[1][0] = dp[2][0] = 1;

		for(int i=1;i<MAX_VAL;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = dp[i-1][j];
				if(j >= nums[i])
					dp[i][j] += dp[i][j-nums[i]];
			}
		}
		printf("%d\n",dp[MAX_VAL-1][n]);
	}
    return 0;
}