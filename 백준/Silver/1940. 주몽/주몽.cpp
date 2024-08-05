#include <stdio.h>
#include <algorithm>

#define MAX_NUM 100000

using namespace std;

bool nums[MAX_NUM];

int main(void)
{
    int N,M;
    scanf("%d %d",&N,&M);

    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);

        nums[num] = true;
    }

    int result = 0;
    for(int i=1;i<=MAX_NUM;i++){
        if(i == M-i || M-i >= MAX_NUM || i >= M)
            continue;

        if(nums[i] && nums[M-i]){
            result++;
            nums[i] = nums[M-i] = false;
        }
    }
    printf("%d\n",result);
    return 0;
}