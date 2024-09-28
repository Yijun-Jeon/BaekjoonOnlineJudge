#include <stdio.h>
#include <algorithm>

#define MAX_N 10000

using namespace std;

int N;
int nums[MAX_N+1];

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    int prev = 0;
    int right = N-1;
    while(right >= 0 && nums[right] > prev){
        prev = nums[right];
        right--;
    }

    if(right < 0){
        printf("-1\n");
        return 0;
    }
    sort(&nums[right+1],&nums[N]);
    for(int i=right+1;i<N;i++){
        if(nums[right] < nums[i]){
            swap(nums[right],nums[i]);        
            break;
        }
    }

    for(int i=0;i<N;i++)
        printf("%d ",nums[i]);
    printf("\n");
    return 0;
}