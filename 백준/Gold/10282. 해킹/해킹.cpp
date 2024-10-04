#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 10000

using namespace std;

bool infected[MAX_N+1];
vector<pair<int,int> > graph[MAX_N+1];

void init(){
    memset(infected,false,sizeof(infected));
    for(int i=0;i<=MAX_N;i++)
        graph[i].clear();
}

pair<int,int> dijkstra(int start){
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));

    int cnt = 0;
    int lastTime = 0;
    while(!pq.empty()){
        int time = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(infected[cur])
            continue;
        infected[cur] = true;
        
        cnt++;
        lastTime = time;

        for(auto next: graph[cur]){
            if(infected[next.first] == false)
                pq.push(make_pair(-(time+next.second),next.first));
        }
    }
    return make_pair(cnt,lastTime);
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int t=0;t<T;t++){
        init();
        
        int n,d,c;
        scanf("%d %d %d",&n,&d,&c);

        for(int i=0;i<d;i++){
            int a,b,s;
            scanf("%d %d %d",&a,&b,&s);

            graph[b].push_back(make_pair(a,s));
        }

        auto result = dijkstra(c);
        printf("%d %d\n",result.first,result.second);
    }
    return 0;
}