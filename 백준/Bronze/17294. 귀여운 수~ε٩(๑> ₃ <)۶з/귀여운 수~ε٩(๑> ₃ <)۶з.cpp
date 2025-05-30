#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S;
    cin >> S;

    if(S.size() > 1){
        int diff = S[1] - S[0];
        for(int i=2;i<S.size();i++){
            if(S[i] - S[i-1] != diff){
                cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << '\n';
                return 0;
            }
        }
    }

    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << '\n';
    return 0;
}