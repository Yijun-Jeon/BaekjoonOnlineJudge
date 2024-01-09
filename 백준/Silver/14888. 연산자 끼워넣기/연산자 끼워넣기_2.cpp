#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    scanf("%d",&N);

    int nums[N];
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    vector<int> opVec;
    for(int i=0;i<4;i++){
        int op;
        scanf("%d",&op);

        // + , - , * , %
        while(op--)
            opVec.push_back(i);
    }

    int maxResult = -1e9;
    int minResult = 1e9;
    do{
        int result = nums[0];

        for(int i=1;i<N;i++){
            switch(opVec[i-1]){
            case 0:
                result += nums[i];
                break;
            case 1:
                result -= nums[i];
                break;
            case 2:
                result *= nums[i];
                break;
            case 3:
                result /= nums[i];
                break;
            }
        }

        maxResult = max(maxResult,result);
        minResult = min(minResult,result);
    }while(next_permutation(opVec.begin(),opVec.end()));

    printf("%d\n%d\n",maxResult,minResult);
    return 0;
}