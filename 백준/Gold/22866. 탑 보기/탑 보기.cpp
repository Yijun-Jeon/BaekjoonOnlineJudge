#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 100000

using namespace std;

int N;
int buildins[MAX_N+1];
// pair<개수,pair<최단거리,건물번호>>
pair<int,pair<int,int> > canSee[MAX_N+1];

bool comp(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}

bool isCloser(pair<int,int> a, pair<int,int> b, int building){
    int distA = abs(a.second - building);
    int distB = abs(b.second - building);

    if(distA == distB)
        return a.second < b.second;
    return distA < distB;
}

int main(void)
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&buildins[i]);

    // height, idx
    vector<pair<int,int> > dp;
    dp.push_back(make_pair(buildins[1],1));

    for(int i=2;i<=N;i++){
        pair<int,int> target = make_pair(buildins[i],i);
        int idx;
        if(buildins[i] < dp.back().first)
            dp.push_back(target);
        else{
            idx = lower_bound(dp.begin(),dp.end(),target,comp) - dp.begin();
            dp[idx] = target;
            dp.erase(dp.begin()+idx+1,dp.end());
        }

        canSee[i].first = dp.size()-1;
        if(dp.size() > 1)
            canSee[i].second = dp[dp.size()-2];
    }

    dp.clear();
    dp.push_back(make_pair(buildins[N],N));
    for(int i=N-1;i>=0;i--){
        pair<int,int> target = make_pair(buildins[i],i);
        int idx;
        if(buildins[i] < dp.back().first)
            dp.push_back(target);
        else{
            idx = lower_bound(dp.begin(),dp.end(),target,comp) - dp.begin();
            dp[idx] = target;
            dp.erase(dp.begin()+idx+1,dp.end());
        }

        canSee[i].first += dp.size()-1;
        if(dp.size() > 1){
            if(canSee[i].second.first == 0 || isCloser(dp[dp.size()-2],canSee[i].second,i))
                canSee[i].second = dp[dp.size()-2];
        }
    }

    for(int i=1;i<=N;i++){
        printf("%d ",canSee[i].first);
        if(canSee[i].first != 0)
            printf("%d",canSee[i].second.second);
        printf("\n");
    }
    return 0;
}