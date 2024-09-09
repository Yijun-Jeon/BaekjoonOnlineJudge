#include <stdio.h>
#include <algorithm>

#define MAX_N 200000

using namespace std;

int N,C;
int homes[MAX_N];

int binarySearch(int start, int end){
    while(start <= end){
        int mid = (start+end)/2;

        int cnt = 1;
        int prev = homes[0];
        for(int i=1;i<N;i++){
            if(homes[i]-prev >= mid){
                cnt++;
                prev = homes[i];
            }
        }

        if(cnt >= C)
            start = mid+1;
        else
            end = mid-1;
    }
    return start-1;
}

int main(void)
{
    scanf("%d %d",&N,&C);
    for(int i=0;i<N;i++)
        scanf("%d",&homes[i]);

    sort(homes,homes+N);

    printf("%d\n",binarySearch(0,homes[N-1]));
    return 0;
}