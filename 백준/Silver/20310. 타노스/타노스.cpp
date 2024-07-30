#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S;
    cin >> S;

    int total0 = 0, total1 = 0;
    for(int i=0;i<S.size();i++){
        if(S[i] == '0') total0++;
        else total1++;
    }


    queue<char> q;
    int cnt0 = 0, cnt1 = 0;
    for(int i=0;i<S.size();i++){
        if(S[i] == '0' && cnt0 < total0/2){
            q.push(S[i]);
            cnt0++;
        }else if(S[i] == '1'){
            if(cnt1 < total1/2)
                cnt1++;
            else
                q.push(S[i]);
        }
    }

    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
    cout << '\n';
    return 0;
}