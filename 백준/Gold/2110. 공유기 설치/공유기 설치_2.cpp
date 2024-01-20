#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N,C;
vector<int> homes;

int binarySearch(int start, int end){
    int result = 0;
    while(start <= end){
        int mid = (start+end)/2;

        int cnt = 1;
        int prev = homes[0];
        for(int i=1;i<N;i++){
            int now = homes[i];
            if(now - prev >= mid){
                cnt++;
                prev = now;
            }
        }
        
        if(cnt >= C){
            start = mid+1;
            result = max(result,mid);
        }
        else
            end = mid-1;
    }
    return result;
}

int main(void)
{
    scanf("%d %d",&N,&C);
    for(int i=0;i<N;i++){
        int home;
        scanf("%d",&home);

        homes.push_back(home);
    }

    sort(homes.begin(),homes.end());

    printf("%d\n",binarySearch(1,homes[N-1]-homes[0]));
    return 0;
}