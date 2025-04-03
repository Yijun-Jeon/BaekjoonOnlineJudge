#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    scanf("%d",&N);

    vector<int> nums(N);
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    sort(nums.begin(),nums.end());

    vector<pair<int,pair<int,int> > > sums;
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++)
            sums.push_back(make_pair(nums[j]+nums[i],make_pair(-j,-i)));
    }

    sort(sums.begin(),sums.end());

    int idx = 0;
    int result = 0;
    for(int i=0;i<sums.size();i++){
        while(idx < N && nums[idx] < sums[i].first)
            idx++;

        while(idx < N && sums[i].first == nums[idx]){
            if(sums[i].second.first != -idx && sums[i].second.second != -idx){
                result++;
                idx++;
            }else break;
        }
    }
    printf("%d\n",result);
    return 0;
}