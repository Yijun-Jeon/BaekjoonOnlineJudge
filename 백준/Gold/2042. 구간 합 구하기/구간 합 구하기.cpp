#include <stdio.h>

#define MAX_N 1000000

using namespace std;

long long segTree[MAX_N*2+2];
int N,M,K;

void update(int b, long long c){
    segTree[b+N] = c;
    for(int i=(b+N)>>1;i>0;i >>= 1)
        segTree[i] = segTree[i<<1] + segTree[(i<<1)+1];
}

long long query(int left, int right){
    long long result = 0;
    for(left += N, right += N; left<=right; left >>= 1, right >>= 1){
        if(left%2 == 1) result += segTree[left++];
        if(right%2 == 0) result += segTree[right--];
    }
    return result;
}

int main(void)
{
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1;i<=N;i++)
        scanf("%lld",&segTree[i+N]);

    for(int i=N;i>0;i--)
        segTree[i] = segTree[i<<1] + segTree[(i<<1)+1];

    for(int i=0;i<M+K;i++){
        int a,b;
        long long c;
        scanf("%d %d %lld",&a,&b,&c);

        if(a == 1) update(b,c);
        else if(a == 2) printf("%lld\n",query(b,c));
    }
    return 0;
}