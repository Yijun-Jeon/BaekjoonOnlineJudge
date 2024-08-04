#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[26];

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string name;
    cin >> name;

    sort(name.begin(),name.end());

    for(int i=0;i<name.size();i++)
        alpha[name[i]-'A']++;

    char middle = '0';
    for(int i=0;i<26;i++){
        if(alpha[i]%2 == 1){
            if(middle != '0'){
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
            middle = i + 'A';
            alpha[i]--;
        }
    }

    string temp;
    for(int i=0;i<26;i++){
        while(alpha[i]){
            temp += i + 'A';
            alpha[i] -= 2;
        }
    }
    string result = temp;
    if(middle != '0')
        result += middle;
    
    reverse(temp.begin(),temp.end());
    result += temp;

    cout << result << '\n';
    return 0;
}