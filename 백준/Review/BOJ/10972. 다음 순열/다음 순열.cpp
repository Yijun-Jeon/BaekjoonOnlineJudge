#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX_N 10000

using namespace std;

int nums[MAX_N+1];

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    vector<int> descending;
    int prev = 0;
    int idx = N-1;
    for(;idx>=0;idx--){
        if(nums[idx] < prev)
            break;
        descending.push_back(nums[idx]);
        prev = nums[idx];
    }

    if(descending.size() == N){
        printf("-1\n");
        return 0;
    }

    swap(*lower_bound(descending.begin(),descending.end(),nums[idx]),nums[idx]);
    
    for(int i=0;i<=idx;i++)
        printf("%d ",nums[i]);
    for(int i=0;i<descending.size();i++)
        printf("%d ",descending[i]);
    printf("\n");
    return 0;
}