#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
    
struct PW{
    int num;
    int cnt;
    int first;
};

bool comp(PW a, PW b){
    if(a.cnt == b.cnt)
        return a.first < b.first;
    return a.cnt > b.cnt;
}

int main(void)
{
    int N,C;
    scanf("%d %d",&N,&C);

    vector<PW> pws;
    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);

        bool found = false;
        for(int j=0;j<pws.size();j++){
            if(pws[j].num == num){
                pws[j].cnt++;
                found = true;
                break;
            }
        }

        if(found == false){
            PW pw = {num,1,i};
            pws.push_back(pw);    
        }
    }

    sort(pws.begin(),pws.end(),comp);

    for(int i=0;i<pws.size();i++){
        for(int j=0;j<pws[i].cnt;j++)
            printf("%d ",pws[i].num);
    }
    printf("\n");
    return 0;
}