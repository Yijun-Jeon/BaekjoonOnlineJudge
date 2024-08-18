#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

int nums[3];
pair<int,int> dp[2][3];

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=0;i<3;i++){
        scanf("%d",&nums[i]);

        dp[0][i].first = dp[0][i].second = nums[i];
    }

    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++)
            scanf("%d",&nums[j]);

        dp[i&1][0].first = max(dp[(i-1)&1][0].first,dp[(i-1)&1][1].first) + nums[0];
        dp[i&1][0].second = min(dp[(i-1)&1][0].second,dp[(i-1)&1][1].second) + nums[0];

        dp[i&1][1].first = max(dp[(i-1)&1][0].first,max(dp[(i-1)&1][1].first,dp[(i-1)&1][2].first)) + nums[1];
        dp[i&1][1].second = min(dp[(i-1)&1][0].second,min(dp[(i-1)&1][1].second,dp[(i-1)&1][2].second)) + nums[1];

        dp[i&1][2].first = max(dp[(i-1)&1][1].first,dp[(i-1)&1][2].first) + nums[2];
        dp[i&1][2].second = min(dp[(i-1)&1][1].second,dp[(i-1)&1][2].second) + nums[2];
    }

    printf("%d %d\n",max(dp[(N-1)&1][0].first,max(dp[(N-1)&1][1].first,dp[(N-1)&1][2].first)),
        min(dp[(N-1)&1][0].second,min(dp[(N-1)&1][1].second,dp[(N-1)&1][2].second)));
    return 0;
}