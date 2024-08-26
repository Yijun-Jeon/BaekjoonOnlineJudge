#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int alplas[26];
int tempAlphas[26];

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    string S;
    cin >> S;

    for(int i=0;i<S.size();i++)
        alplas[S[i]-'A']++;

    int result = 0;
    for(int n=1;n<N;n++){
        string temp;
        cin >> temp;

        if(abs((int)S.size()-(int)temp.size()) >= 2)
            continue;

        memset(tempAlphas,0,sizeof(tempAlphas));
        for(int i=0;i<temp.size();i++)
            tempAlphas[temp[i]-'A']++;

        int adjust = 0;
        bool similar = true;
        for(int i=0;i<26;i++){
            if(abs(alplas[i]-tempAlphas[i]) > 1){
                similar = false;
                break;
            }

            if(abs(alplas[i]-tempAlphas[i]) == 1){
                if(abs((int)temp.size() - (int)S.size()) == 1){
                    if(adjust) similar = false;
                    else adjust++;
                }else{
                    if(adjust > 2) similar = false;    
                    else adjust++;
                }
            }
        }  

        if(similar) result++;
    }
    cout << result << '\n';
    return 0;
}