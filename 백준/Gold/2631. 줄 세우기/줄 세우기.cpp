#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    scanf("%d",&N);

    int nums[N];
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);
    
    int dp[N];
    dp[0] = nums[0];

    int result = 1;
    for(int i=1;i<N;i++){
        if(dp[result-1] < nums[i])
            dp[result++] = nums[i];
        else
            *lower_bound(&dp[0],&dp[result],nums[i]) = nums[i];
    }

    printf("%d\n",N-result);
    return 0;
}