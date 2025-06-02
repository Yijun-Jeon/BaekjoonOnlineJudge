#include <iostream>
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

    int result = N;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int numer = nums[j]-nums[i];
            int denomi = j-i;
            if(numer%denomi)
                continue;

            int diff = numer/denomi;

            int cnt = 0;
            for(int k=0;k<N;k++){
                int target = k < i ? nums[i]-diff*(i-k) : nums[i]+diff*(k-i);
                if(nums[k] != target)
                    cnt++;
            }

            result = min(result,cnt);
        }
    }
    cout << result << '\n';
    return 0;
}