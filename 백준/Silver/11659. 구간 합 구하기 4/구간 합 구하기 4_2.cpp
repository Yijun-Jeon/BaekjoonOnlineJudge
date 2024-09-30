#include <stdio.h>

#define MAX_N 100000

using namespace std;

int main(void)
{
    int N,M;
    scanf("%d %d",&N,&M);

    int segTree[N*2+2];
    for(int i=1;i<=N;i++)
        scanf("%d",&segTree[i+N]);

    for(int i=N;i>0;i--)
        segTree[i] = segTree[i<<1] + segTree[(i<<1) + 1];

    for(int i=0;i<M;i++){
        int left,right;
        scanf("%d %d",&left,&right);

        int result = 0;
        for(left+=N, right+=N; left <= right; left>>=1, right>>=1){
            if(left%2 == 1) result += segTree[left++];
            if(right%2 == 0) result += segTree[right--];
        }

        printf("%d\n",result);
    }
    return 0;
}