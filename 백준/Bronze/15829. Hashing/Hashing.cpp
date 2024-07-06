#include <iostream>
#include <string>

#define R 31
#define M 1234567891

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int L;
    string s;

    cin >> L >> s;

    long long result = 0;
    for(int i=0;i<L;i++){
        long long num = s[i] - 'a' + 1;
        for(int j=0;j<i;j++)
            num = (num*R) % M;
        result = (result+num) % M;
    }
    cout << result << '\n';
    return 0;
    
}