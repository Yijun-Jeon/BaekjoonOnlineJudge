#include <stdio.h>
#include <algorithm>

#define MAX_N 200000

using namespace std;

int N;
int fruits[MAX_N+1];


int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&fruits[i]);

    pair<int,pair<int,int> > prev,now;
    prev.first = 1;
    prev.second.first = prev.second.second = 0;

    int result = 1;
    for(int i=1;i<N;i++){
        if(fruits[i] == fruits[prev.second.second]){
            now = prev;
            now.first++;
        }
        else if(fruits[i] == fruits[prev.second.first]){
            now.first = prev.first+1;
            now.second.first = prev.second.second;
            now.second.second = i;
        }
        else{
            now.first = i-prev.second.second + 1;
            now.second.first = prev.second.second;
            now.second.second = i;
        }
        
        result = max(result,now.first);
        prev = now;
    }
    printf("%d\n",result);
    return 0;
}