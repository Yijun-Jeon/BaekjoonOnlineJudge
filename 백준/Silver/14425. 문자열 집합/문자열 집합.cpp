#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N,M;
    cin >> N >> M;

    vector<string> S(N);

    for(int i=0;i<N;i++)
        cin >> S[i];
    sort(S.begin(),S.end());

    int cnt = 0;
    for(int i=0;i<M;i++){
        string temp;
        cin >> temp;

        int idx = lower_bound(S.begin(),S.end(),temp) - S.begin();
        cnt +=  S[idx] == temp && idx < N;
    }
    cout << cnt << endl;
    return 0;
}