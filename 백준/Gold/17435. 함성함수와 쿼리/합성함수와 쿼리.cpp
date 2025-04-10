#include <iostream>
#include <cmath>

#define MAX_M 200000
#define MAX_K 18

using namespace std;

int parent[MAX_K+1][MAX_M+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int M;
    cin >> M;

    for(int i=1;i<=M;i++)
        cin >> parent[0][i];

    for(int k=1;k<=MAX_K;k++){
        for(int i=1;i<=M;i++)
            parent[k][i] = parent[k-1][parent[k-1][i]];
    }

    int Q;
    cin >> Q;
    
    while(Q--){
        int n,x;
        cin >> n >> x;

        for(int k=MAX_K; k>=0; k--){
            if(pow(2,k) <= n){
                x = parent[k][x];
                n -= pow(2,k);
            }
        }
        while(n--)
            x = parent[0][x];
        cout << x << '\n';
    }
    return 0;
}