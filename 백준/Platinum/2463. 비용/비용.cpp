#include <stdio.h>
#include <queue>

#define MAX_N 100000
#define DENOMI 1000000000

using namespace std;

pair<int,int> parents[MAX_N+1];
priority_queue<pair<int,pair<int,int> > > pq;

pair<int,int> Find(int x){
    if(x == parents[x].first)
        return parents[x];
    return parents[x] = Find(parents[x].first);
}

void Union(int x, int y){
    pair<int,int> parentX = Find(x);
    pair<int,int> parentY = Find(y);

    if(parentX.first != parentY.first){
        parents[parentX.first].second += parentY.second;
        parents[parentY.first] = parents[parentX.first];
    }
}

int main(void)
{
    int N,M;
    scanf("%d %d",&N,&M);

    for(int i=1;i<=N;i++)
        parents[i] = make_pair(i,1);

    long long total = 0;
    for(int i=0;i<M;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        total += w;

        pq.push(make_pair(w,make_pair(x,y)));
    }

    long long result = 0;
    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        pair<int,int> parentX = Find(x);
        pair<int,int> parentY = Find(y);
        
        if(parentX.first != parentY.first){
            Union(x,y);
            result += (total * parentX.second * parentY.second) % DENOMI;
            result %= DENOMI;
        }

        total -= cost;
    }
    printf("%lld\n",result);
    return 0;
}