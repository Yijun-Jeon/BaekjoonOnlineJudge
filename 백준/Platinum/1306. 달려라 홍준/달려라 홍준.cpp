#include <stdio.h>
#include <algorithm>

#define MAX_N 1000000

using namespace std;

int N,M;
int segTree[MAX_N*2+2];

int query(int left, int right){
    int result = 0;
    for(left+=N, right+=N; left<=right; left>>=1, right>>=1){
        if(left%2 == 1) result = max(result,segTree[left++]);
        if(right%2 == 0) result = max(result,segTree[right--]);
    }
    return result;        
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&segTree[i+N]);

    for(int i=N;i>0;i--)
        segTree[i] = max(segTree[i<<1],segTree[(i<<1)+1]);

    for(int i=1;i<=N-2*M+2;i++)
        printf("%d ",query(i,i+2*M-2));    
    printf("\n");
    return 0;
}