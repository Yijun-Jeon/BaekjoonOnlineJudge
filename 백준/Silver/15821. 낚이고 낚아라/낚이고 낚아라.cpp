#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;
    vector<long long> vec(N,0);
    for(int n=0;n<N;n++){
        int P;
        cin >> P;
        for(int p=0;p<P;p++){
            long long x,y;
            cin >> x >> y;

            vec[n] = max(vec[n],x*x + y*y);
        }
    }
    sort(vec.begin(),vec.end());

    cout << vec[K-1] << ".00" << '\n';
    return 0;
}
