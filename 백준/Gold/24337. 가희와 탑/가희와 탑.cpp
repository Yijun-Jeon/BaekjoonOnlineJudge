#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N,a,b;
    scanf("%d %d %d",&N,&a,&b);

    vector<int> result;
    for(int i=1;i<a;i++)
        result.push_back(i);
    result.push_back(max(a,b));
    for(int i=b-1;i>0;i--)
        result.push_back(i);

    if(result.size() > N){
        printf("-1\n");
        return 0;
    }

    while(result.size() < N){
        if(result[0] == 1)
            result.insert(result.begin(),1);
        else
            result.insert(result.begin()+1,1);
    }

    for(int i=0;i<N;i++)
        printf("%d ",result[i]);
    printf("\n");
    return 0;
}