#include <stdio.h>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int dp[MAX_N];
int nums[MAX_N];

int main(void)
{
	int N;
	scanf("%d", &N);

	for(int i=0;i<N;i++){
		scanf("%d", &nums[i]);
		dp[i] = 1;
	}

	int result = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			if(nums[j] < nums[i])
				dp[i] = max(dp[i],dp[j] + 1);
		}
		result = max(result,dp[i]);
	}

	printf("%d\n",result);  
    return 0;
}

