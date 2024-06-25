#include <stdio.h>
#include <stack>

#define MAX_N 1000

using namespace std;

int N;
int nums[MAX_N+1];
pair<int,int> dp[MAX_N+1];

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    int idx = 0;
    int result = 0;
    for(int i=0;i<N;i++){
        dp[i].first = -1;
        dp[i].second = 1;
        for(int j=i-1;j>=0;j--){
            if(nums[i] > nums[j]){
                if(dp[i].second < dp[j].second + 1){
                    dp[i].second = dp[j].second + 1;
                    dp[i].first = j;
                }
            }
        }
        if(result < dp[i].second){
            result = dp[i].second;
            idx = i;
        }
    }

    stack<int> stk;
    while(idx >= 0){
        stk.push(nums[idx]);
        idx = dp[idx].first;
    }

    printf("%d\n",(int)stk.size());
    while(!stk.empty()){
        printf("%d ",stk.top());
        stk.pop();
    }
    printf("\n");
    return 0;
}