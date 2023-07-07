#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N;

    map<int,int> cards;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;

        auto iter = cards.find(num);
        if(iter != cards.end())
            iter->second++;
        else
            cards.insert(pair<int,int>(num,1));
    }

    cin >> M;
    for(int i=0;i<M;i++){
        int num;
        cin >> num;

        auto iter = cards.find(num);
        if(iter != cards.end())
            cout << iter->second << ' ';
        else
            cout << 0 << ' ';
    }
    cout << '\n';
    return 0;
}