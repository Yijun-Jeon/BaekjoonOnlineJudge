#include <stdio.h>
#include <algorithm>

#define MAX_N 10000

using namespace std;

int N,M;
int cities[MAX_N];

int binarySearch(int start, int end){
    while(start <= end){
        int mid = (start+end)/2;

        int sum = 0;
        for(int i=0;i<N;i++){
            if(cities[i] <= mid)
                sum += cities[i];
            else sum += mid;
        }

        if(sum <= M)
            start = mid+1;
        else
            end = mid-1;
    }

    return end;
}

int main(void)
{
    scanf("%d",&N);

    int total = 0;
    for(int i=0;i<N;i++){
        scanf("%d",&cities[i]);
        total += cities[i];
    }

    sort(&cities[0],&cities[N]);
    scanf("%d",&M);

    if(M >= total){
        printf("%d\n",cities[N-1]);
        return 0;
    }

    printf("%d\n",binarySearch(0,cities[N-1]));
    return 0;
}