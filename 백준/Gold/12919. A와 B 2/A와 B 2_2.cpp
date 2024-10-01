#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A;

bool DFS(string B){
    if(A == B)
        return true;

    if(A.size() == B.size())
        return false;

    if(B[B.size()-1] == 'A'){
        if(DFS(B.substr(0,B.size()-1)))
            return true;
    }

    if(B[0] == 'B'){
        string r = B.substr(1,B.size()-1);    
        reverse(r.begin(),r.end());
        if(DFS(r))
            return true;
    }
    return false;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string B;
    cin >> A >> B;

    cout << DFS(B) << '\n';
    return 0;
}