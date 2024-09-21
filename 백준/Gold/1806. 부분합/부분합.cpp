#include <stdio.h>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N,S;
int nums[MAX_N];

int main(void)
{
    scanf("%d %d",&N,&S);

    int total = 0;
    for(int i=0;i<N;i++){
        scanf("%d",&nums[i]);
        total += nums[i];
    }

    if(total < S){
        printf("0\n");
        return 0;
    }

    int result = N, sum = 0;
    for(int left=0,right=0;right<N;right++){
        sum += nums[right];
        while(left <= right && sum - nums[left] >= S){
            sum -= nums[left];
            left++;
        }

        if(sum >= S)
            result = min(result,right-left+1);
    }
    printf("%d\n",result);
    return 0;
}S