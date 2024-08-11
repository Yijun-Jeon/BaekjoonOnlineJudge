#include <stdio.h>
#include <queue>

#define MAX_NUM 65536

using namespace std;

int N,K;
int segTree[MAX_NUM*4];

void update(int idx, bool isAdd){
    for(idx += MAX_NUM*2; idx>0; idx>>=1){
        if(isAdd) segTree[idx]++;
        else segTree[idx]--;
    }
}

int query(int idx, int k){
    if(MAX_NUM*2 <= idx)
        return idx - MAX_NUM*2;
    
    if(segTree[idx<<1] < k)
        return query((idx<<1)+1,k-segTree[idx<<1]);
    else
        return query(idx<<1,k);
}

int main(void)
{
    scanf("%d %d",&N,&K);

    queue<int> nums;
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