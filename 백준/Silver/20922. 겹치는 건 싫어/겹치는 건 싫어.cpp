#include <stdio.h>
#include <algorithm>
#include <queue>

#define MAX_N 200000
#define MAX_A 100000

using namespace std;

int nums[MAX_N+1];
int dp[MAX_N+1];
queue<int> q[MAX_A+1];

int main(void)
{
    int N,K;
    scanf("%d %d",&N,&K);

    for(int i=1;i<=N;i++)
        scanf("%d",&nums[i]);

    int result = 0;
    for(int i=1;i<=N;i++){
        if(q[nums[i]].size() < K){
            dp[i] = dp[i-1] + 1; 
        }else{
            int start = q[nums[i]].front();
            q[nums[i]].pop();

            dp[i] = min(dp[i-1]+1,i - start);
        }
        q[nums[i]].push(i);
        result = max(result,dp[i]);
    }
    printf("%d\n",result);
    return 0;
}