#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

unordered_map<string,bool> m;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        string keyword;
        cin >> keyword;

        m[keyword] = true;
    }

    for(int i=0;i<M;i++){
        string S;
        cin >> S;

        string keyword;
        for(int j=0;j<S.size();j++){
            if(S[j] == ','){
                auto iter = m.find(keyword);
                if(iter != m.end())
                    m.erase(iter);
                keyword = "";
            }
            else keyword += S[j];
        }

        auto iter = m.find(keyword);
        if(iter != m.end())
            m.erase(iter);

        cout << m.size() << '\n';
    }
    return 0;
}