#include <stdio.h>

using namespace std;

int main(void)
{
    int nums[8];

    bool ascending = false;
    bool descending = false;
    for(int i=0;i<8;i++){
        scanf("%d",&nums[i]);

        if(ascending)
            ascending = nums[i] == nums[i-1] + 1;
        if(descending)
            descending = nums[i] == nums[i-1] - 1;

        if(i == 0){
            if(nums[i] == 1)
                ascending = true;
            else if(nums[i] == 8)
                descending = true;
        }
    }

    if(ascending) printf("ascending\n");
    else if(descending) printf("descending\n");
    else printf("mixed\n");
    return 0;
}