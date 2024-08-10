#include <stdio.h>
#include <algorithm>

#define MAX_N 5000000
#define MAX_NUM 1e9

using namespace std;

int N,L;
int segTree[MAX_N*2+2];

int query(int left, int right){
    int result = MAX_NUM;

    for(left+=N, right+=N; left<=right; left>>=1,right>>=1){
        if(left%2 == 1) result = min(result,segTree[left++]);
        if(right%2 == 0) result = min(result,segTree[right--]);
    }
    return result;
}

int main(void)
{
    scanf("%d %d",&N,&L);
    fill(&segTree[0],&segTree[2*N+2],MAX_NUM);
    
    for(int i=1;i<=N;i++)
        scanf("%d",&segTree[i+N]);

    for(int i=N;i>0;i--)
        segTree[i] = min(segTree[i<<1],segTree[(i<<1)+1]);

    for(int i=1;i<=N;i++)
        printf("%d ",query(max(1,i-L+1),i));
    printf("\n");
    return 0;
}