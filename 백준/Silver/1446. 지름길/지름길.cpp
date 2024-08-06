#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX_D 10000

using namespace std;

int dp[MAX_D+1];

int main(void)
{
    int N,D;
    scanf("%d %d",&N,&D);

    fill(&dp[1],&dp[MAX_D+1],MAX_D);

    vector<pair<pair<int,int>,int> > vec;
    for(int i=0;i<N;i++){
        int start,end,len;
        scanf("%d %d %d",&start,&end,&len);

        vec.push_back(make_pair(make_pair(start,end),len));
    }
    sort(vec.begin(),vec.end());

    int car = 0;
    int idx = 0;
    while(car < D){
        if(car > 0) dp[car] = min(dp[car],dp[car-1]+1);

        while(idx < vec.size() && car == vec[idx].first.first){
            dp[vec[idx].first.second] = min(dp[vec[idx].first.second],dp[car]+vec[idx].second);
            idx++;
        }
        car++;
    }
    printf("%d\n",min(dp[D],dp[D-1]+1));
    return 0;
}