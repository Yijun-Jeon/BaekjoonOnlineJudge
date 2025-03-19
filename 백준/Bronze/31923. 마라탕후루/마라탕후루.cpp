#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,P,Q;
    cin >> N >> P >> Q;

    vector<pair<int,int> > vec(N);

    for(int i=0;i<N;i++)
        cin >> vec[i].first;
    for(int i=0;i<N;i++)
        cin >> vec[i].second;

    vector<int> result(N);
    for(int i=0;i<N;i++){
        if(Q-P == 0){
            if(vec[i].first != vec[i].second){
                cout << "NO" << '\n';
                return 0;
            }
            result[i] = 0;
            continue;
        }
        
        int diff = vec[i].first - vec[i].second;
        if(diff % (Q-P) != 0 || diff / (Q-P) < 0 || diff / (Q-P) > 10000){
            cout << "NO" << '\n';
            return 0;
        }
        result[i] = diff / (Q-P);
    }
    cout << "YES" << '\n';
    for(int i=0;i<N;i++)
        cout << result[i] << " ";
    cout << '\n';
    return 0;
}