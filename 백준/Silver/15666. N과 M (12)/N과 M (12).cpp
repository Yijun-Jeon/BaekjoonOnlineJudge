#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX_N 8

using namespace std;

int N,M;
int nums[MAX_N];
vector<int> result;

void DFS(int last, int cnt){
    if(cnt == M){
        for(int i=0;i<result.size();i++)
            printf("%d ",result[i]);
        printf("\n");
        return;
    }

    int prev = 0;
    for(int i=last;i<N;i++){
        if(prev != nums[i]){
            result.push_back(nums[i]);
            DFS(i,cnt+1);
            result.pop_back();
            prev = nums[i];
        }
    }
}


int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);

    sort(&nums[0],&nums[N]);

    DFS(0,0);
    return 0;
}