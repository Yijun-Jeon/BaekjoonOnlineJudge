#include <stdio.h>
#include <algorithm>

#define MAX_N 10000

using namespace std;

long long N,K;

long long binarySearch(long long start, long long end){
    while(start <= end){
        long long mid = (start+end)/2;

        long long cnt = 0;
        for(int n=1;n<=N;n++)
            cnt += min(N,mid/n);

        if(cnt < K)
            start = mid+1;
        else
            end = mid-1;
    }
    return start;
}

int main(void)
{
    scanf("%lld %lld",&N,&K);
    printf("%lld\n",binarySearch(1,N*N));
    return 0;
}