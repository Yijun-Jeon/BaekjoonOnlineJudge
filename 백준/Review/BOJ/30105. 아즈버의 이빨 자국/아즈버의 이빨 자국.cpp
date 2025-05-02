#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 4000

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int nums[N];
    unordered_map<int,bool> map;
    for(int i=0;i<N;i++){
        cin >> nums[i];
        map[nums[i]] = true;
    }

    vector<int> result;
    for(int size=1;size<N;size++){
        int diff = nums[size] - nums[0];
    
        bool valid = true;
        for(int i=0;i<N && valid;i++){
            if(!(map[nums[i]-diff] || map[nums[i]+diff]))
                valid = false;
        }

        if(valid)
            result.push_back(diff);
    }

    cout << result.size() << '\n';

    if(result.empty())
        return 0;
    
    for(int i=0;i<result.size();i++)
        cout << result[i] << " " ;
    cout  << '\n';
    return 0;
}