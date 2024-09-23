#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S,bomb;
vector<char> stack;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> S >> bomb;

    for(int i=0;i<S.size();i++){
        stack.push_back(S[i]);
        if(stack.size() < bomb.size())
            continue;
        
        bool isBomb = true;
        for(int i=0;i<bomb.size();i++){
            if(stack[i+stack.size()-bomb.size()] != bomb[i]){
                isBomb = false;
                break;
            }
        }

        if(isBomb)
            stack.erase(stack.end()-bomb.size(),stack.end());
    }

    if(stack.empty()){
        cout << "FRULA" << '\n';
        return 0;
    }

    for(int i=0;i<stack.size();i++)
        cout << stack[i];
    cout << '\n';
    return 0;
}