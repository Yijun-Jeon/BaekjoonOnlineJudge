#include <string>
#include <vector>

using namespace std;

bool isBalanced(string s){
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(')
            cnt++;
        else if(s[i] == ')')
            cnt--;
    }
    return cnt == 0;
}

bool isRight(string s){
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(')
            cnt++;
        else if(s[i] == ')'){
            if(cnt == 0)
                return false;
            else
                cnt--;
        }
    }
    return true;
}

string func(string s){
    if(s == "")
        return s;
    
    int i = 1;
    while(!isBalanced(s.substr(0,i)))
        i++;
    
    // u는 균형잡힌 문자열
    string u = s.substr(0,i);
    string v = s.substr(i,s.size() - i);

    // u가 올바른 문자열
    if(isRight(u)){
        return u + func(v);
    }
    // u가 올바른 문자열 X
    else{
        string result = "(";
        result += func(v);
        result += ")";
        
        for(int i=1;i<u.size()-1;i++)
            result += u[i] == '(' ? ')' : '(';
        return result;
    }
}

string solution(string p) {
    string answer = func(p);
    return answer;
}