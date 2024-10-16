#include <iostream>
#include <vector>

#define MAX_MIN 188888888888888

using namespace std;

int N;
// cnt, num
vector<pair<int,int> > nums;

long long result;

void smallDFS(int sum, string s){
    if(!s.empty() && (stoll(s) >= MAX_MIN+1 || stoll(s) >= result))
        return;

    if(sum == N){
        result = stoll(s);
        return;
    }

    for(int i=0;i<nums.size();i++){
        if(sum+nums[i].first <= N){
            if(sum+nums[i].first == N && nums[i].second == 0)
                continue;
            smallDFS(sum+nums[i].first,to_string(nums[i].second)+s);
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    nums.push_back(make_pair(6,0));
    nums.push_back(make_pair(7,8));
    nums.push_back(make_pair(6,6));
    nums.push_back(make_pair(5,2));
    nums.push_back(make_pair(2,1));
    nums.push_back(make_pair(4,4));
    nums.push_back(make_pair(3,7));

    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        cin >> N;

        result = MAX_MIN+1;

        int sum = 0;
        string s;
        while(N - sum > 7*3){
            s += "8";
            sum += 7;
        }

        smallDFS(sum,s);
        cout << result << " ";

        s = "";
        if(N%2) s += "7";
        else s += "1";

        for(int i=0;i<(N-2)/2;i++)
            s += "1";

        cout << s << "\n";
    }
    return 0;
}