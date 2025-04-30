#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100

using namespace std;

bool used[MAX_N];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    vector<pair<int,int> > daily(M);
    for(int i=0;i<M;i++){
        cin >> daily[i].first >> daily[i].second;

        if(daily[i].first + daily[i].second > N){
            cout << "NO" << '\n';
            return 0;
        }
    }

    char result[N][M];

    int totalRest = 0;
    for(int i=0;i<M;i++){
        int sum = daily[i].first + daily[i].second;
        int canRest = max(0, N-sum);
        for(int j=0;j<N;j++){
            if(canRest && used[j] == false){
                canRest--;
                totalRest++;
                used[j] = true;
                result[j][i] = 'X';
                continue;
            }else if(daily[i].first){
                result[j][i] = '+';
                daily[i].first--;
            }else if(daily[i].second){
                result[j][i] = '-';
                daily[i].second--;
            }else{
                result[j][i] = '+';
            }
        }
    }

    if(totalRest < N){
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << result[i][j];
        }
        cout << '\n';
    }
    return 0;
}