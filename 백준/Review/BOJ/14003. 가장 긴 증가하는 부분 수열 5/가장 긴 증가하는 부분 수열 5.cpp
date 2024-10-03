#include <stdio.h>
#include <vector>

#define MAX_N 1000000

using namespace std;

int idx = 1;
int nums[MAX_N], dp[MAX_N], indexs[MAX_N];

int binarySearch(int num){
    int left = 0, right = idx-1;
    while(left<=right){
        int mid = (left+right)/2;

        if(dp[mid] == num)
            return mid;

        if(dp[mid] < num)
            left = mid+1;
        else
            right = mid-1;
    }
    return left;
}

int main(void)
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    dp[0] = nums[0];
    indexs[0] = 0;
    for(int i=1;i<N;i++){
        if(nums[i] > dp[idx-1]){
            indexs[i] = idx;
            dp[idx++] = nums[i];
        }
        else{
            int index = binarySearch(nums[i]);
            dp[index] = nums[i];
            indexs[i] = index;
        }
    }

    printf("%d\n",idx);

    vector<int> result(idx);
    for(idx -= 1; idx >= 0; idx--){
        while(indexs[--N] != idx);

        result[idx] = nums[N];
    }

    for(int i=0;i<result.size();i++)
        printf("%d ",result[i]);
    printf("\n");
    return 0;
}