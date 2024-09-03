#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int result = 0;
    for(int n=0;n<N;n++){
        string S;
        cin >> S;

        if(S.size()%2)
            continue;

        string temp;
        temp += S[0];
        for(int i=1;i<S.size();i++){
            if(!temp.empty() && S[i] == temp.back())
                temp.pop_back();
            else
                temp.push_back(S[i]);
        }

        if(temp.empty())
            result++;
    }

    cout << result << '\n';
    return 0;
}