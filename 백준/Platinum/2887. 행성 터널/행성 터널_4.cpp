#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define MAX_N 100000

using namespace std;

int N;
vector<pair<int,int> > xVec;
vector<pair<int,int> > yVec;
vector<pair<int,int> > zVec;

int parents[MAX_N];

int Find(int x){
    if(x == parents[x])
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
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0;i<N;i++){
        int x,y,z;
        cin >> x >> y >> z;

        xVec.push_back(make_pair(x,i));
        yVec.push_back(make_pair(y,i));
        zVec.push_back(make_pair(z,i));

        parents[i] = i;
    }

    sort(xVec.begin(),xVec.end());
    sort(yVec.begin(),yVec.end());
    sort(zVec.begin(),zVec.end());

    priority_queue<pair<int,pair<int,int> > > pq;
    for(int i=1;i<N;i++){
        pq.push(make_pair(-abs(xVec[i].first - xVec[i-1].first),make_pair(xVec[i].second,xVec[i-1].second)));
        pq.push(make_pair(-abs(yVec[i].first - yVec[i-1].first),make_pair(yVec[i].second,yVec[i-1].second)));
        pq.push(make_pair(-abs(zVec[i].first - zVec[i-1].first),make_pair(zVec[i].second,zVec[i-1].second)));
    }

    int edge = 0;
    long long result = 0;
    while(edge < N-1){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(Find(x) == Find(y))
            continue;
        Union(x,y);

        edge++;
        result += cost;
    }
    cout << result << '\n';
    return 0;
}