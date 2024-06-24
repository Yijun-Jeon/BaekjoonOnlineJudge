#include <stdio.h>
#include <algorithm>

#define MAX_H 500

using namespace std;

int H,W;
int map[MAX_H];

int main(void)
{
    scanf("%d %d",&H,&W);
    for(int i=0;i<W;i++)
        scanf("%d",&map[i]);

    int result = 0;
    for(int i=0;i<W;i++){
        int maxLeft = 0, maxRight = 0;

        for(int left=i-1; left>=0; left--)
            maxLeft = max(maxLeft,map[left]);
        for(int right=i+1; right<W;right++)
            maxRight = max(maxRight,map[right]);

        if(maxLeft == 0 || maxRight == 0 || maxLeft < map[i] || maxRight < map[i])
            continue;
        result += min(maxLeft,maxRight) - map[i];
    }
    printf("%d\n",result);
    return 0;
}