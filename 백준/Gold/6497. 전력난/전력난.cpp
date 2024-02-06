#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 200000

using namespace std;

int parents[MAX_N+1];

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
    while(true){
        int m,n;
        scanf("%d %d",&m,&n);
        if(m == 0 && n == 0)
            break;

        for(int i=0;i<=m;i++)
            parents[i] = i;

        vector<pair<int,pair<int,int> > > edges(n);
        int total = 0;
        for(int i=0;i<n;i++){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);

            edges[i] = make_pair(z,make_pair(x,y));
            total += z;
        }

        sort(edges.begin(),edges.end());
        int result = 0;
        int edge = 0;
        int idx = 0;
        for(int i=0;i<n;i++){
            if(edge == m-1)
                break;

            int cost = edges[i].first;
            int x = edges[i].second.first;
            int y = edges[i].second.second;

            if(Find(x) == Find(y))
                continue;

            Union(x,y);
            result += cost;
            edge++;
        }
        printf("%d\n",total - result);
    }
    return 0;
}