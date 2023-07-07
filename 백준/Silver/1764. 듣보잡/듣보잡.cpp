#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    vector<string> unListen(N);
    for(int i=0;i<N;i++){
        string name;
        cin >> name;
        unListen[i] = name;
    }
    sort(unListen.begin(),unListen.end());

    vector<string> unListenAndSeen;
    for(int i=0;i<M;i++){
        string name;
        cin >> name;

        int idx = lower_bound(unListen.begin(),unListen.end(),name) - unListen.begin();
        if(unListen[idx] == name && idx < unListen.size())
            unListenAndSeen.push_back(name);
    }

    sort(unListenAndSeen.begin(),unListenAndSeen.end());

    cout << unListenAndSeen.size() << '\n';
    for(int i=0;i<unListenAndSeen.size();i++)
        cout << unListenAndSeen[i] << '\n';
    return 0;
}