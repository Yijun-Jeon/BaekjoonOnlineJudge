#include <stdio.h>
#include <queue>

#define MAX_N 30000

using namespace std;

int N,d,k,c;
int nums[MAX_N+1];
int taken[MAX_N+1];

int useCoupon(int cnt){
    if(taken[c])
        return cnt;
    return cnt+1;
}

int main(void)
{
    scanf("%d %d %d %d",&N,&d,&k,&c);

    int cnt = 0;
    queue<int> q;
    for(int i=1;i<=N;i++){
        scanf("%d",&nums[i]);
        if(q.size() < k){
            q.push(nums[i]);
            
            if(!taken[nums[i]]++)
                cnt++;
        }
    }

    int result = useCoupon(cnt);
    for(int i=k+1;i<N+k;i++){
        if(--taken[q.front()] == 0)
            cnt--;
        q.pop();

        int idx = (i-1)%N+1;
        if(!taken[nums[idx]]++)
            cnt++;
        q.push(nums[idx]);

        result = max(result,useCoupon(cnt));
    }
    
    printf("%d\n",result);
    return 0;
}