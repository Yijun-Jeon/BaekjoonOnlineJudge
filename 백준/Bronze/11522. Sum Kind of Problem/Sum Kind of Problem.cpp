#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int P;
    cin >> P;

    for(int i=0;i<P;i++){
        int K,N;
        cin >> K >> N;

        int S1 = N*(N+1)/2;

        cout << K << " " << S1 << " " << 2*S1-N << " " << 2 * S1 << '\n';
    }
    return 0;
}