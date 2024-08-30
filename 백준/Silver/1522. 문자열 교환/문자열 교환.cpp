#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 1001

using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S;
    cin >> S;
    
    int cntB = 0;
    int result = MAX_N;
    for(int i=0;i<S.size();i++){
        if(S[i] == 'b')
            cntB++;
    }

    for(int i=0;i<S.size();i++){
        if(S[i] == 'a')
            continue;

        string temp = S;
        int start = i;

        int end = (i+S.size()-1) % S.size();
        while(end != start && temp[end] == 'a')
            end = (end+S.size()-1) % S.size();

        int cnt = cntB-1;
        int exchange = 0;
        for(int idx=(start+1) % S.size();idx != start;idx = (idx+1)%S.size()){
            if(cnt <= 0)
                break;
            
            if(temp[idx] == 'a'){
                if(start == end)
                    continue;
                swap(temp[idx],temp[end]);
                while(end >= 0 && temp[end] == 'a')
                    end--;
                exchange++;
            }
            cnt--;
        }
        result = min(result,exchange);
    }
    
    if(result == MAX_N) result = 0;
    cout << result << '\n';
    return 0;
}