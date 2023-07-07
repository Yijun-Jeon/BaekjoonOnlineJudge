#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    unordered_map<string,int> pokemons_name_num;
    unordered_map<int,string> pokemons_num_name;
    for(int i=0;i<N;i++){
        string name;
        cin >> name;
        pokemons_name_num.insert(pair<string,int>(name,i+1));
        pokemons_num_name.insert(pair<int,string>(i+1,name));
    }

    for(int i=0;i<M;i++){
        string temp;
        cin >> temp;

        if('0' <= temp[0] && temp[0] <= '9')
            cout << pokemons_num_name.find(stoi(temp))->second << '\n';
        else
            cout << pokemons_name_num.find(temp)->second << '\n';
    }
    return 0;
}