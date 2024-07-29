#include <iostream>

#define MAX_N 20000

using namespace std;

int N,K;
// 0 : 먹은 햄버거, 1 : 햄버거, 2 : 사랑
int table[MAX_N];

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    
    string s;
    cin >> s;

    for(int i=0;i<N;i++){
        if(s[i] == 'H')
            table[i] = 1;
        else if(s[i] == 'P')
            table[i] = 2;
    }

    int result = 0;
    for(int i=0;i<N;i++){
        if(table[i] == 2){
            int idx = i-K < 0 ? 0 : i-K;
            for(; idx< N && idx <= i+K; idx++){
                if(table[idx] == 1){
                    table[idx] = 0;
                    result++;
                    break;
                }
            }
        }
    }
    
    cout << result << '\n';
    return 0;
}