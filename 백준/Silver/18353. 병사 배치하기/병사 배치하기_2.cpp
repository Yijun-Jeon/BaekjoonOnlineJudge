#include <stdio.h>

#define MAX_N 2000

using namespace std;

int main(void)
{
    int N;
    scanf("%d",&N);

    int nums[N], dp[N];;
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    dp[0] = nums[0];
    int idx = 1;
    for(int i=1;i<N;i++){
        if(nums[i] < dp[idx-1])
            dp[idx++] = nums[i];
        else{
            int left = 0, right = idx-1;
            while(left <= right){
                int mid = (left+right)/2;

                if(dp[mid] == nums[i]){
                    left = mid;
                    break;
                }

                if(dp[mid] > nums[i])
                     left = mid+1;
                else
                    right = mid-1;
            }
            dp[left] = nums[i];
        }
    }

    printf("%d\n",N-idx);
    return 0;
}