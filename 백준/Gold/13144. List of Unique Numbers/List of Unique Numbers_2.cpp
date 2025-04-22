#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int pos[MAX_N+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int nums[N+1];
    for(int i=1;i<=N;i++)
        cin >> nums[i];

    long long result = nums[0] = 0;
    for(int i=1;i<=N;i++){
        if(pos[nums[i]] == 0){
            pos[nums[i]] = i;
            nums[i] = 1+nums[i-1];
            result += (long long)nums[i];
        }else{
            int temp = min(nums[i-1],i-pos[nums[i]]-1)+1;
            pos[nums[i]] = i;
            nums[i] = temp;
            result += (long long)nums[i];
        }
    }
    cout << result << '\n';
    return 0;
}