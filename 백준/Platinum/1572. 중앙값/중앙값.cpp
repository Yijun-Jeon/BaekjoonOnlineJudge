#include <stdio.h>
#include <queue>

#define MAX_NUM 65536

using namespace std;

int N,K;
int segTree[MAX_NUM*4];
queue<int> nums;

void update(int num, bool isAdd){
    for(int idx = MAX_NUM*2 + num; idx>0;idx >>= 1){
        if(isAdd) segTree[idx]++;
        else segTree[idx]--;
    }
}

int query(int idx,int k){
    if(MAX_NUM*2 <= idx)
        return idx - MAX_NUM*2;

    if(k <= segTree[(idx<<1)])
        return query(idx<<1,k);
    else
        return query((idx<<1)+1,k-segTree[(idx<<1)]);
}

int main(void)
{
    scanf("%d %d",&N,&K);

    long long result = 0;
    for(int i=1;i<=N;i++){
        int num;
        scanf("%d",&num);

        nums.push(num);

        update(num,true);
        if(i < K) continue;

        result += query(1,K/2 + (K&1));
        update(nums.front(),false);
        nums.pop();

    }
    printf("%lld\n",result);
    return 0;
}