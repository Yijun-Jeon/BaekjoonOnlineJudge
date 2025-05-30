#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int nums[n];
    for(int i=0;i<n;i++)
        cin >> nums[i];

    long long result = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result += abs(nums[i] - nums[j]);
        }
    }
    cout << result << '\n';
    return 0;
}