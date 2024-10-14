#include <stdio.h>
#include <cmath>
#include <stack>

#define MAX_N 100000

using namespace std;

// pair<개수,pair<건물높이,건물번호>>
pair<int,pair<int,int> > canSee[MAX_N+1];

bool isCloser(pair<int,int> a, pair<int,int> b, int building){
    if(b.first == 0)
        return true;
    int distA = abs(a.second - building);
    int distB = abs(b.second - building);

    if(distA == distB)
        return a.second < b.second;
    return distA < distB;
}

int main(void)
{
    int N;
    scanf("%d",&N);

    int buildins[N+1];
    for(int i=1;i<=N;i++)
        scanf("%d",&buildins[i]);

    // height, idx
    stack<pair<int,int> > stk;
    stk.push(make_pair(buildins[1],1));

    for(int i=2;i<=N;i++){
        pair<int,int> target = make_pair(buildins[i],i);
        while(!stk.empty() && stk.top().first <= target.first)
            stk.pop();

        if(!stk.empty())
            canSee[i].second = stk.top();
        canSee[i].first += stk.size();

        stk.push(target);
    }

    while(!stk.empty())
        stk.pop();
    stk.push(make_pair(buildins[N],N));

    for(int i=N-1;i>=1;i--){
        pair<int,int> target = make_pair(buildins[i],i);
        while(!stk.empty() && stk.top().first <= target.first)
            stk.pop();

        if(!stk.empty() && isCloser(stk.top(),canSee[i].second,i))
            canSee[i].second = stk.top();
        canSee[i].first += stk.size();

        stk.push(target);
    }

    for(int i=1;i<=N;i++){
        printf("%d ",canSee[i].first);
        if(canSee[i].first != 0)
            printf("%d",canSee[i].second.second);
        printf("\n");
    }
    return 0;
}