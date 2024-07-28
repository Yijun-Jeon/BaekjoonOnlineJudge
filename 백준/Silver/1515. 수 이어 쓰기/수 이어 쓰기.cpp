#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int result = 1;
    int numIdx = 0;
    for(int i=0;i<s.size();i++){
        bool found = false;
        while(!found){
            string num = to_string(result);
            for(int j=numIdx;j<num.size();j++){
                if(num[j] == s[i]){
                    found = true;
                    if(j == num.size()-1)
                        numIdx = 0;
                    else 
                        numIdx = j+1;
                    break;
                }
            }

            if(!found) numIdx = 0;

            if(numIdx == 0)
                result++;
        }
    }

    if(numIdx > 0) result++;
    cout << result-1 << "\n";
    return 0;
}