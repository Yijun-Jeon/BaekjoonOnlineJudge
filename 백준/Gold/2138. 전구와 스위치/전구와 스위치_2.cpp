#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    string from,to;
    cin >> from >> to;

    int result = MAX_N+1;
    int cnt = 0;
    for(int j=0;j<2;j++){
        string temp = from;
        for(int i=1;i<N;i++){
            if(temp[i-1] != to[i-1]){
                temp[i-1] ^= 1;
                temp[i] ^= 1;
                if(i<N-1)
                    temp[i+1] ^= 1;
                cnt++;
            }
        }

        if(temp == to)
            result = min(result,cnt);

        from[0] ^= 1;
        from[1] ^= 1;
        cnt = 1;
    }
    if(result == MAX_N+1) result = -1;
    cout << result << '\n';
    return 0;
}