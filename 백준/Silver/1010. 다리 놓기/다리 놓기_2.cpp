#include <stdio.h>
#include <algorithm>

using namespace std;

long long factorial(int m, int n){
    if(m <= n)
        return 1;
    return m * factorial(m-1,n);
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int t=0;t<T;t++){
        int N,M;
        scanf("%d %d",&N,&M);

        long long result = factorial(M,max(M-N,N))/factorial(min(M-N,N),1);
        printf("%lld\n",result);
    }
    return 0;
}