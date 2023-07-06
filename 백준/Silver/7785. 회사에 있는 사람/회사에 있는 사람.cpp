#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<string,string,greater<string> > members;
    for(int i=0;i<n;i++){
        string name, log;
        cin >> name >> log;

        auto iter = members.find(name);
        if(iter != members.end())
            members.erase(iter);
        else
            members.insert(pair<string,string>(name,log));
    }
    for(auto it=members.begin(); it != members.end(); it++)
        cout << it->first << '\n';
    return 0;
}