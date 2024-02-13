#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// pos, index
vector<pair<int,int> > posX;
vector<pair<int,int> > posY;
vector<pair<int,int> > posZ;

int N;
int parents[MAX_N];

priority_queue<pair<int,pair<int,int> > > pq;

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
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);

        posX.push_back(make_pair(x,i));
        posY.push_back(make_pair(y,i));
        posZ.push_back(make_pair(z,i));

        parents[i] = i;
    }
    sort(posX.begin(),posX.end());
    sort(posY.begin(),posY.end());
    sort(posZ.begin(),posZ.end());

    for(int i=0;i<N-1;i++){
        pq.push(make_pair(-(posX[i+1].first - posX[i].first),make_pair(posX[i].second,posX[i+1].second)));
        pq.push(make_pair(-(posY[i+1].first - posY[i].first),make_pair(posY[i].second,posY[i+1].second)));
        pq.push(make_pair(-(posZ[i+1].first - posZ[i].first),make_pair(posZ[i].second,posZ[i+1].second)));
    }

    int edge = 0;
    int result = 0;
    while(edge < N-1){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(Find(x) == Find(y))
            continue;

        result += cost;
        Union(x,y);
        edge++;
    }
    printf("%d\n",result);
    return 0;
}