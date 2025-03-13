#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cmath>

#define MAX_N 1000

using namespace std;

bool pages[MAX_N+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        int N;
        cin >> N;

        if(N == 0)
            break;

        memset(pages,false,sizeof(pages));

        string S;
        cin >> S;

        istringstream ss(S);
        string s;
        vector<string> subVec;

        while(getline(ss,s,','))
            subVec.push_back(s);

        for(auto s: subVec){
            istringstream ss(s);
            string num;
            vector<string> nums;

            while(getline(ss,num,'-'))
                nums.push_back(num);

            int start = stoi(nums.front());
            int end = stoi(nums.back());

            for(int i=start; i<=end; i++){
                if(i>N)
                    break;
                pages[i] = true;
            }
        }

        int result = 0;
        for(int i=1;i<=N;i++){
            if(pages[i]) result++;
        }
        cout << result << '\n';
    }
    return 0;
}