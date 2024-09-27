#include <stdio.h>
#include <cstring>

#define MAX_N 100000

using namespace std;

int main(void)
{
    long long N;
    scanf("%lld",&N);

    int nums[N];
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    bool check[MAX_N+1];
    memset(check,false,sizeof(check));

    int left = 0, right = 0;
    long long result = N*(N+1)/2;
    while(right < N){
        if(check[nums[right]]){
            result -= (N-right);
            check[nums[left++]] = false;
        }else
            check[nums[right++]] = true;
    }
    printf("%lld\n",result);
    return 0;
}