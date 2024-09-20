#include <stdio.h>
#include <algorithm>

#define MAX_N 2000

using namespace std;

int nums[MAX_N+1];

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=1;i<=N;i++)
        scanf("%d",&nums[i]);

    sort(&nums[1],&nums[N+1]);

    int result = 0;
    for(int i=1;i<=N;i++){
        int l=1, r=N;
        while(l < r){
            if(l == i){
                l++;
                continue;
            }
            if(r == i){
                r--;
                continue;
            }

            int sum = nums[l]+nums[r];
            if(sum == nums[i]){
                result++;      
                break;      
            }else if(sum > nums[i])
                r--;
            else
                l++;
        }
    }        
    printf("%d\n",result);
    return 0;
}