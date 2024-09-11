#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX_N 100000

using namespace std;

int parents[MAX_N];

int Find(int x){
    if(parents[x] == x)
        return x;
    return parents[x] = Find(parents[x]);
}

void Union(int x, int y){
    int parentX = Find(x);
    int parentY = Find(y);

    if(parentX != parentY)
        parents[parentY] = parentX;
}

int main(void)
{
    int N;
    scanf("%d",&N);

    vector<pair<int,int> > xVec(N);
    vector<pair<int,int> > yVec(N);
    vector<pair<int,int> > zVec(N);

    for(int n=0;n<N;n++){
        scanf("%d %d %d",&xVec[n].first,&yVec[n].first,&zVec[n].first);
        xVec[n].second = yVec[n].second = zVec[n].second = n;

        parents[n] = n;
    }

    sort(xVec.begin(),xVec.end());
    sort(yVec.begin(),yVec.end());
    sort(zVec.begin(),zVec.end());

    priority_queue<pair<int,pair<int,int> > > pq;
    for(int n=1;n<N;n++){
        pq.push(make_pair(-abs(xVec[n].first-xVec[n-1].first),make_pair(xVec[n-1].second,xVec[n].second)));
        pq.push(make_pair(-abs(yVec[n].first-yVec[n-1].first),make_pair(yVec[n-1].second,yVec[n].second)));
        pq.push(make_pair(-abs(zVec[n].first-zVec[n-1].first),make_pair(zVec[n-1].second,zVec[n].second)));
    }

    long long result = 0;
    int edge = 0;
    while(edge < N-1){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(Find(x) == Find(y))
            continue;

        Union(x,y);
        result += cost;
        edge++;
    }
    printf("%lld\n",result);
    return 0;
}