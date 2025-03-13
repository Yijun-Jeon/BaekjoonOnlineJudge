#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int N,K;
    scanf("%d %d",&N,&K);

    // weight, cost
    pair<int,int> jewelry[N];
    for(int i=0;i<N;i++)
        scanf("%d %d",&jewelry[i].first,&jewelry[i].second);

    sort(&jewelry[0],&jewelry[N]);

    vector<int> bags(K);

    for(int i=0;i<K;i++)
        scanf("%d",&bags[i]);

    sort(bags.begin(),bags.end());

    int idx = 0;
    priority_queue<int> pq;

    long long total = 0;
    for(int k=0;k<K;k++){
        while(idx < N && jewelry[idx].first <= bags[k])
            pq.push(jewelry[idx++].second);

        if(pq.empty())
            continue;

        total += pq.top();
        pq.pop();
    }
    printf("%lld\n",total);
    return 0;
}