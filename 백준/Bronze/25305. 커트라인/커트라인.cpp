#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N,k;
    cin >> N >> k;

    int scores[N];
    for(int i=0;i<N;i++)
        cin >> scores[i];

    sort(scores,scores+N);
    cout << scores[N-k] << endl;
    return 0;
}