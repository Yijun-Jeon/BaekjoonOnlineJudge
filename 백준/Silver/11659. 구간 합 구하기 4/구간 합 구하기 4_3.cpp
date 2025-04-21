#include <iostream>

#define MAX_N 100000

using namespace std;

int N,M;
int segtree[MAX_N*2+2];

int func(int left, int right){
    int result = 0;
    for(left+=N,right+=N; left<=right; left>>=1, right>>=1){
        if(left%2) result += segtree[left++];
        if(right%2 == 0) result += segtree[right--];
    }
    return result;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int n=1;n<=N;n++)
        cin >> segtree[N+n];

    for(int n=N;n>0;n--)
        segtree[n] = segtree[n<<1] + segtree[(n<<1) + 1];

    while(M--){
        int left,right;
        cin >> left >> right;

        cout << func(left,right) << '\n';
    }
    return 0;
}