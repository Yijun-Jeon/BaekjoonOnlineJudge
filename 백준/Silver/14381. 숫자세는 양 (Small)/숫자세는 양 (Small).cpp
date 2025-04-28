#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        int N;
        cin >> N;

        cout << "Case #" << t << ": ";

        if(N == 0){
            cout << "INSOMNIA" << '\n';
            continue;
        }

        int cnt = 0, n = 0;
        bool nums[10] = {0};

        while(cnt < 10){
            n += N;
            string S = to_string(n);
            for(int i=0;i<S.size();i++){
                if(nums[S[i]-'0'] == false){
                    nums[S[i]-'0'] = true;
                    cnt++;
                }
            }
        }
        cout << n << '\n';
    }
    return 0;
}