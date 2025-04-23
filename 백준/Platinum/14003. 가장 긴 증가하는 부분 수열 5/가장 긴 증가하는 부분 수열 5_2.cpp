#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int nums[N];
    for(int i=0;i<N;i++)
        cin >> nums[i];

    int history[N],dp[N];

    int idx = 0;
    history[0] = 1;
    dp[idx++] = nums[0];
    for(int i=1;i<N;i++){
        if(dp[idx-1] < nums[i]){
            dp[idx++] = nums[i];
            history[i] = idx;
        }
        else{
            int pos = lower_bound(&dp[0],&dp[idx],nums[i]) - &dp[0];
            dp[pos] = nums[i];
            history[i] = pos+1;
        }
    }

    int result[idx];
    cout << idx << '\n';
    int last = 1e9+1, pos = idx;
    for(int i=N-1;i>=0;i--){
        if(history[i] != pos)
            continue;

        if(last <= nums[i])
            continue;

        result[pos-1] = nums[i];
        last = nums[i];
        pos--;
    }
    
    for(int i=0;i<idx;i++)
        cout << result[i] << " ";
    cout << '\n'; 
    return 0;
}