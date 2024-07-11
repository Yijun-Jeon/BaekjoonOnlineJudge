#include <stdio.h>

#define MAX_N 100000

using namespace std;

int N,M;
int nums[MAX_N];
int segTree[2*MAX_N];

int query(int left, int right){
    int result = 0;

    for(;left <= right; left >>= 1, right >>= 1){
        if(left & 1) result += segTree[left++];
        if(!(right & 1)) result += segTree[right--];
    }

    return result;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    for(int i=0;i<N;i++)
        segTree[N+i] = nums[i];
    for(int i=N-1; i != 0; i--)
        segTree[i] = segTree[i << 1] + segTree[i<<1 | 1];

    for(int i=0;i<M;i++){
        int left,right;
        scanf("%d %d",&left,&right);

        printf("%d\n",query(left+N-1,right+N-1));
    }
    return 0;
}