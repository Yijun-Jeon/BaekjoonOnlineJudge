#include <iostream>
#include <cmath>

using namespace std;

int nums[10][7] =
    {1,1,1,0,1,1,1
    ,0,0,1,0,0,1,0
    ,1,0,1,1,1,0,1
    ,1,0,1,1,0,1,1
    ,0,1,1,1,0,1,0
    ,1,1,0,1,0,1,1
    ,1,1,0,1,1,1,1
    ,1,0,1,0,0,1,0
    ,1,1,1,1,1,1,1
    ,1,1,1,1,0,1,1};

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K,P,numX;
    cin >> N >> K >> P >> numX;

    string X = to_string(numX);

    while(X.size() < K)
        X = "0" + X;

    int result = 0;
    for(int n=1;n<=N;n++){
        if(n == numX)
            continue;

        string x = to_string(n);    
        while(x.size() < K)
            x = "0" + x;

        int diff = 0;
        for(int i=0;i<K;i++){
            for(int j=0;j<7;j++)
                diff += abs(nums[X[i]-'0'][j] - nums[x[i]-'0'][j]);
        }

        if(diff <= P)
            result++;
    }
    cout << result << '\n';
    return 0;
}