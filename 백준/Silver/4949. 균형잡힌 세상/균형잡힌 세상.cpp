#include <iostream>
#include <stack>
#include <string>

#define MAX_LEN 100

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    while(true){
        string s;
        getline(cin,s);

        if(s == ".")
            break;

        stack<char> stk;
        bool valid = true;
        for(int i=0;i<s.size() && valid;i++){
            if(s[i] == '(' || s[i] == '[')
                stk.push(s[i]);
            else if(s[i] == ')'){
                if(stk.empty() || stk.top() != '(')
                    valid = false;
                else
                    stk.pop();
            }else if(s[i] == ']'){
                if(stk.empty() || stk.top() != '[')
                    valid = false;
                else
                    stk.pop();
            }
        }

        if(stk.empty() && valid) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}