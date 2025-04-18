#include <stdio.h>

#define MAX_N 500

using namespace std;

int N;
int nums[MAX_N+1], dp[MAX_N+1];

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int t=1;t<=T;t++){
        scanf("%d",&N);

        for(int i=0;i<N;i++)
            scanf("%d",&nums[i]);

        int result = 0;
        for(int i=0;i<N;i++){
            int idx = 0;
            for(int j=i;j<N;j++){
                if(idx == 0 || dp[idx-1] < nums[j])
                    dp[idx++] = nums[j];
                else{
                    int left = 0, right = idx-1;
                    while(left<=right){
                        int mid = (left+right)/2;

                        if(dp[mid] == nums[j]){
                            left = mid;
                            break;
                        }

                        if(dp[mid] < nums[j])
                            left = mid+1;
                        else
                            right = mid-1;
                    }
                    dp[left] = nums[j];
                }
                result += idx;
            }
        }
        printf("Case #%d: %d\n",t,result);
    }
    return 0;
}