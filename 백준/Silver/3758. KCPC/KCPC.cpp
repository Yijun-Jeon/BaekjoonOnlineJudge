#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 100

using namespace std;

struct Team
{
    int teamID;
    int scores[MAX_N+1];
    int totalScore;
    int submitCount;
    int lastSubmit;
};

bool comp(Team a, Team b){
    if(a.totalScore == b.totalScore){
        if(a.submitCount == b.submitCount)
            return a.lastSubmit < b.lastSubmit;
        return a.submitCount < b.submitCount;
    }
    return a.totalScore > b.totalScore;
}

int main(void)
{
    int Testcase;
    scanf("%d",&Testcase);

    for(int testcase=0;testcase<Testcase;testcase++){

        int N,K,T,M;
        scanf("%d %d %d %d",&N,&K,&T,&M);

        vector<Team> teams(N);
        for(int i=0;i<N;i++)
            teams[i].teamID = i+1;

        for(int m=0;m<M;m++){
            int teamID,pNum,score;
            scanf("%d %d %d",&teamID,&pNum,&score);

            int lastScore = teams[teamID-1].scores[pNum];
            if(lastScore < score){
                teams[teamID-1].totalScore += (score - lastScore);
                teams[teamID-1].scores[pNum] = score;
            }
            teams[teamID-1].submitCount++;
            teams[teamID-1].lastSubmit = m;
        }

        sort(teams.begin(),teams.end(),comp);
        for(int i=0;i<N;i++){
            if(teams[i].teamID == T){
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}