#include <iostream>
#include <cmath>

#define DENOMI 1000000007

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    long long result = 2;
    for(int i=2;i<=N;i++){
        result *= 3;
        result = (result+2) % DENOMI;
    }
    cout << result << '\n';
    return 0;
}
