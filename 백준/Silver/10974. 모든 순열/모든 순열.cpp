#include <stdio.h>
#include <algorithm>

#define MAX_N 8

using namespace std;

int nums[MAX_N];
int N;

int main(void)
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        nums[i-1] = i;

    do{
        for(int i=0;i<N;i++)
            printf("%d ",nums[i]);
        printf("\n");
    }while(next_permutation(&nums[0],&nums[N]));
    return 0;
}