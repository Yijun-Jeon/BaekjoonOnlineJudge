#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

int main(void)
{
    for(int t=0;t<3;t++){
        int N;
        scanf("%d",&N);

        int total = 0;
        pair<int,int> coins[N];
        for(int i=0;i<N;i++){
            scanf("%d %d",&coins[i].first,&coins[i].second);
            total += coins[i].first * coins[i].second;
        }
        
        bool dp[total+1];
        memset(dp,false,sizeof(dp));

        queue<pair<int,int> > q;
        q.push(make_pair(0,-1));

        bool found = false;
        for(int i=0;i<N && !found;i++){
            while(q.front().second < i){
                int cur = q.front().first;
                for(int k=1;k<=coins[i].second && !found;k++){
                    int idx = q.front().first + coins[i].first * k;
                    if(dp[idx] == false){
                        dp[idx] = true;
                        q.push(make_pair(idx,i));
                    }
                    if(2*idx == total)
                        found = true;
                }
                q.push(q.front());
                q.pop();    
            }
        }

        if(found) printf("1\n");
        else printf("0\n");
    }
    return 0;
}