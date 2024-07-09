#include <map>
#include <iostream>
#include <string>

using namespace std;

int N,M;
map<string,string> m;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        string addr,pw;
        cin >> addr >> pw;

        m[addr] = pw;
    }

    for(int i=0;i<M;i++){
        string addr;
        cin >> addr;

        cout << m[addr] << '\n';    
    }
    return 0;
}