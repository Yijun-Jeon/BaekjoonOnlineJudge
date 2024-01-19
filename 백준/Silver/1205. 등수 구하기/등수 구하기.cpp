#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> nums;
    int N,P,score;

    scanf("%d %d %d",&N,&score,&P);
    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);

        nums.push_back(num);
    }

    sort(nums.begin(),nums.end());
    
    int idx = nums.end() - upper_bound(nums.begin(),nums.end(),score);

    int result;
    if(N < P || nums[N-P] < score)
        result = idx+1;
    else
        result = -1;

    printf("%d\n",result);
    return 0;
}