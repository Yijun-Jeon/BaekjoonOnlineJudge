#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

string S,T;

bool DFS(){
    if(S.size() == T.size())
        return S == T;

    string rS = S;
    reverse(rS.begin(),rS.end());

    size_t found = T.find(S);
    size_t rfound = T.find(rS);

    if(found == string::npos && rfound == string::npos)
        return false;

    S.push_back('A');
    if(DFS())
        return true;

    S.pop_back();
    S.push_back('B');
    reverse(S.begin(),S.end());

    if(DFS())
        return true;

    reverse(S.begin(),S.end());
    S.pop_back();

    return false;
}

int main(void)
{
    cin >> S >> T;

    printf("%d\n",DFS());
    return 0;
}