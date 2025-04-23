#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int A[N+1];
    int B[N+1];
    int pos[N+1];

    for(int i=1;i<=N;i++)
        cin >> A[i];

    for(int i=1;i<=N;i++){
        int B;
        cin >> B;
        pos[B] = i;
    }

    vector<int> dp;
    dp.push_back(pos[A[1]]);
    for(int i=2;i<=N;i++){
        int next = pos[A[i]];
        if(dp.back() < next)
            dp.push_back(next);
        else{
            *lower_bound(dp.begin(),dp.end(),next) = next;
        }
    }
    cout << dp.size() << '\n';
    return 0;
}