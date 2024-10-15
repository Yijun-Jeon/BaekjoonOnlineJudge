#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

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

        sort(&coins[0],&coins[N]);
        
        bool dp[total+1];
        short changed[total+1];
        memset(dp,false,sizeof(dp));
        memset(changed,0,sizeof(changed));

        dp[0] = true;
        changed[0] = -1;

        int sum = 0;
        bool found = false;
        for(int i=0;i<N && !found;i++){
            for(int j=0;j<=sum && !found;j++){
                if(dp[j] == true && changed[j] != i){
                    for(int k=1;k<=coins[i].second && !found;k++){
                        int idx = j + coins[i].first * k;
                        if(dp[idx] == false){
                            dp[idx] = true;
                            changed[idx] = i;
                        }
                        if(2*idx == total)
                            found = true;
                    }    
                }
            }
            sum += coins[i].first * coins[i].second;
        }

        if(found) printf("1\n");
        else printf("0\n");
    }
    return 0;
}