#include <stdio.h>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int nums[MAX_N+1];

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    sort(nums,nums+N);

    if(nums[0] > 1){
        printf("%d\n",1);
        return 0;
    }

    int acc = nums[0];
    for(int i=1;i<N;i++){
        if(nums[i] - acc > 1)
            break;
        acc += nums[i];
    }
    printf("%d\n",acc+1);
    return 0;
}