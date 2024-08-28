#include <stdio.h>
#include <cstring>

#define MAX_N 1000000

using namespace std;

int nums[MAX_N+1];

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);

        for(int n=0;n<N;n++)
            scanf("%d",&nums[n]);

        int maxRight = nums[N-1];
        long long result = 0;
        for(int i=N-2;i>=0;i--){
            if(nums[i] >= maxRight)
                maxRight = nums[i];
            else
                result += maxRight - nums[i];
        }

        printf("%lld\n",result);
    }
    return 0;
}