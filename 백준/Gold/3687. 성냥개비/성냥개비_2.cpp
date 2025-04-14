#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX_N 100

using namespace std;

long long smalls[MAX_N+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    pair<int,int> smaller[7] = {
        make_pair(0,6),
        make_pair(1,2),
        make_pair(2,5),
        make_pair(4,4),
        make_pair(6,6),
        make_pair(7,3),
        make_pair(8,7),
    };

    while(T--){
        int N;
        cin >> N;

        string large;
        for(int i=0;i<N/2;i++)
            large += "1";
        if(N%2) large[0] = '7';

        priority_queue<pair<long long,int> > pq;
        for(int i=1;i<7;i++)
            pq.push(make_pair(-smaller[i].first,smaller[i].second));

        fill(&smalls[0],&smalls[MAX_N+1],LLONG_MAX);

        while(!pq.empty()){
            long long cost = -pq.top().first;
            int n = pq.top().second;
            pq.pop();

            if(smalls[n] <= cost)
                continue;
            smalls[n] = cost;

            for(int i=0;i<7;i++){
                long long nextCost = cost * 10 + smaller[i].first;
                int nextN = n + smaller[i].second;
                if(nextN <= N && nextCost < smalls[nextN])
                    pq.push(make_pair(-nextCost,nextN));
            }
        }
        cout << smalls[N] << " " << large << '\n';
    }
    return 0;
}