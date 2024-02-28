#include <stdio.h>
#include <list>

#define MAX_N 100

using namespace std;

list<pair<int,bool> > upperList;
list<int> belowList;
int N,K;

int main(void)
{
    scanf("%d %d",&N,&K);

    for(int i=0;i<N;i++){
        int remain;
        scanf("%d",&remain);
        upperList.push_back(make_pair(remain,false));
    }
    for(int i=0;i<N;i++){
        int remain;
        scanf("%d",&remain);
        belowList.push_front(remain);
    }

    int result = 0;
    while(K > 0){
        // 1 stage
        pair<int,bool> upperBack = upperList.back();
        int belowFront = belowList.front();

        upperList.pop_back();
        belowList.pop_front();

        upperList.push_front(make_pair(belowFront,false));
        belowList.push_back(upperBack.first);

        upperList.back().second = false;

        // 2 stage
        for(auto iter = (--(--upperList.end())); iter != upperList.begin(); iter--){
            if(iter->second == false)
                continue;

            auto iterNext = iter;
            iterNext++;
            if(iterNext->first > 0 && iterNext->second == false){
                iter->second = false;

                (iterNext->first)--;
                if(iterNext->first == 0)
                    K--;
                iterNext->second = true;
            }
        }

        // 3 stage
        if(upperList.front().first > 0){
            (upperList.front().first)--;
            if(upperList.front().first == 0)
                K--;
            upperList.front().second = true;
        }

        result++;
    }

    printf("%d\n",result);
    return 0;
}