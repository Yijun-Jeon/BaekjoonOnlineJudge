#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    vector<pair<int,int> > jewelries(N);
    for(int n=0;n<N;n++){
        cin >> jewelries[n].first >> jewelries[n].second;
    }

    vector<int> bags(K);
    for(int k=0;k<K;k++)
        cin >> bags[k];

    sort(jewelries.begin(),jewelries.end());
    sort(bags.begin(),bags.end());

    priority_queue<int> pq;

    int idx = 0;
    long long result = 0;
    for(int i=0;i<K;i++){
        while(idx < N && jewelries[idx].first <= bags[i]){
            pq.push(jewelries[idx++].second);
        }
        if(pq.empty())
            continue;
        result += pq.top();
        pq.pop();
    }
    cout << result << '\n';
    return 0;
}