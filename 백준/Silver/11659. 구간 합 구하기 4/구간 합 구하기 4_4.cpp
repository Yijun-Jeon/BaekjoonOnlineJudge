#include <iostream>

#define MAX_N 100000

using namespace std;

int N,M;
int segtree[MAX_N*2+2];

int Func(int left, int right){
    int sum = 0;
    for(left += N, right += N; left <= right; left >>= 1, right >>= 1){
        if(left % 2) sum += segtree[left++];
        if(right % 2 == 0) sum += segtree[right--];
    }
    return sum;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=1;i<=N;i++)
        cin >> segtree[i+N];

    for(int i=N;i>0;i--)
        segtree[i] = segtree[i<<1] + segtree[(i<<1)+1];

    for(int i=0;i<M;i++){
        int left,right;
        cin >> left >> right;
        cout << Func(left,right) << '\n';
    }
    return 0;
}