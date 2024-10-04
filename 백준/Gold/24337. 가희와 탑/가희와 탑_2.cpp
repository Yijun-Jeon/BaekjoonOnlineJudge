#include <stdio.h>

using namespace std;

int main(void)
{
    int N,a,b;
    scanf("%d %d %d",&N,&a,&b);

    int idx = N-1;
    int left = a, right = 0;
    int nums[N];
    while(idx >= 0 && b-right > 1)
        nums[idx--] = ++right;

    if(idx < 0){
        printf("-1\n");
        return 0;
    }

    if(a == 1){
        for(int i=1;i<=idx;i++)
            nums[i] = 1;
        nums[0] = ++right;
    }else if(a >= b){
        nums[idx--] = left--;

        while(idx >= 0 && left > 1)
            nums[idx--] = left--;

        if(idx < 0){
            printf("-1\n");
            return 0;
        }

        while(idx >= 0)
            nums[idx--] = 1;
    }else{
        nums[idx--] = ++right;
        left--;

        while(idx >= 0 && left > 1)
            nums[idx--] = left--;

        if(idx < 0){
            printf("-1\n");
            return 0;
        }

        while(idx >= 0)
            nums[idx--] = 1;
    }

    for(int i=0;i<N;i++)
        printf("%d ",nums[i]);
    printf("\n");
    return 0;
}