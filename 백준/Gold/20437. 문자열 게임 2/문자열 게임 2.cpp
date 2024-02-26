#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_LEN 10000

using namespace std;

vector<int> alphabet[26];

void init(){
    for(int i=0;i<26;i++)
        alphabet[i].clear();
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int tset_case = 0; tset_case < T; tset_case++){
        init();

        string S;
        cin >> S;

        for(int i=0;i<(int)S.size();i++)
            alphabet[S[i] - 'a'].push_back(i);

        int K;
        scanf("%d",&K);

        int minResult = MAX_LEN;
        int maxResult = 0;
        for(int alpha=0;alpha<26;alpha++){
            if(alphabet[alpha].size() < K)
                continue;

            int minLen = alphabet[alpha][K-1] - alphabet[alpha][0];
            int maxLen = minLen;
            for(int i=K;i<alphabet[alpha].size();i++){
                int len = alphabet[alpha][i] - alphabet[alpha][i+1-K];
                minLen = min(minLen,len);
                maxLen = max(maxLen,len);
            }

            minResult = min(minResult,minLen);
            maxResult = max(maxResult,maxLen);
        }

        if(minResult == MAX_LEN) printf("%d\n",-1);
        else printf("%d %d\n",minResult+1,maxResult+1);
    }
    return 0;
}