#include <stdio.h>
#include <algorithm>
#include <cmath>

#define MAX_N 300000

using namespace std;

int nums[MAX_N+1];

int main(void)
{
    int n;
    scanf("%d",&n);

    if(n == 0){
        printf("0\n");
        return 0;
    }

    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    sort(&nums[0],&nums[n]);

    int sum = 0;
    for(int i=(int)round(n*0.15);i<n-(int)round(n*0.15);i++)
        sum += nums[i];

    printf("%1.0f\n",round(sum/((n-round(n*0.15))-round(n*0.15))));
    return 0;
}