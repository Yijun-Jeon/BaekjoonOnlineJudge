#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#define MAX_N 20000

using namespace std;

int N;
string words[MAX_N];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    unordered_map<string,vector<int> > map;

    cin >> N;
    string head;
    for(int n=0;n<N;n++){
        cin >> words[n];

        string temp;
        for(int i=0;i<words[n].size();i++){
            temp += words[n][i];
            if(map[temp].size() < 2)
                map[temp].push_back(n);

            if(map[temp].size() > 1 && temp.size() > head.size()){
                head = temp;
            }else if(map[temp].size() > 1 && temp.size() == head.size()){
                if(map[temp][0] < map[head][0])
                    head = temp;
            }
        }
    }

    if(head.empty()){
        cout << words[0] << '\n';
        cout << words[1] << '\n';
    }else{
        cout << words[map[head][0]] << '\n';
        cout << words[map[head][1]] << '\n';        
    }
    return 0;
}