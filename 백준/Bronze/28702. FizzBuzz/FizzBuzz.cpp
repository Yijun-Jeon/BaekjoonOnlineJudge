#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int result;
    for(int i=0;i<3;i++){
        string s;
        cin >> s;

        if('0' <= s[0] && s[0] <= '9')
            result = stoi(s) + (3-i);
    }
    if(result%3 == 0 && result%5 == 0) cout << "FizzBuzz";
    else if(result%3 == 0) cout << "Fizz";
    else if(result%5 == 0) cout <<"Buzz";
    else cout << result;
    cout << '\n';
    return 0;
}