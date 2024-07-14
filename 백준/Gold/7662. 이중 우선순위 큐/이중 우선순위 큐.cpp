#include <stdio.h>
#include <queue>
#include <cstring>

#define MAX_K 1000000

using namespace std;

int idx = 0;
bool nums[MAX_K+2];

void init(){
    idx = 0;
    memset(nums,false,sizeof(nums));
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int test_case=0;test_case<T;test_case++){
        init();

        int K;
        scanf("%d",&K);

        priority_queue<pair<long long,int> > maxQ;
        priority_queue<pair<long long,int> > minQ;

        for(int k=0;k<K;k++){
            getchar();

            char op;
            long long num;
            scanf("%c %lld",&op,&num);

            if(op == 'I'){
                maxQ.push(make_pair(num,idx));
                minQ.push(make_pair(-num,idx));
                nums[idx++] = true;
            }

            if(op == 'D'){
                while(!maxQ.empty() && nums[maxQ.top().second] == false)
                    maxQ.pop();
                while(!minQ.empty() && nums[minQ.top().second] == false)
                    minQ.pop();

                if(maxQ.empty())
                    continue;
                else if(num == 1){
                    pair<long long,int> top = maxQ.top();
                    maxQ.pop();

                    nums[top.second] = false;
                }else if(num == -1){
                    pair<long long,int> top = minQ.top();
                    minQ.pop();

                    nums[top.second] = false;
                }
            }
        }

        while(!maxQ.empty() && nums[maxQ.top().second] == false)
            maxQ.pop();
        while(!minQ.empty() &&  nums[minQ.top().second] == false)
            minQ.pop();
        
        if(maxQ.empty())
            printf("EMPTY\n");
        else
            printf("%lld %lld\n",maxQ.top().first,-minQ.top().first);
    }
    return 0;
}