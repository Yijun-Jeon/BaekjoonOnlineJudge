#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A,B,C;
    cin >> A >> B >> C;

    if(B-A == 1 && C-B == 1){
        cout << 0 << '\n';
        return 0;
    }

    if(B-A > C-B) swap(B,C);
    else swap(A,B);

    B = A+1;

    int result = 1;
    while(B+1 < C){
        swap(A,B);
        B = A+1;
        result++;
    }

    cout << result << '\n';
    return 0;
}