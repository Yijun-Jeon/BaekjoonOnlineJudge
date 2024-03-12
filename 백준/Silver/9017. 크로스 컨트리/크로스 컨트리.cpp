#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 1000
#define MAX_TEAM 200

using namespace std;

vector<int> teams[MAX_TEAM+1];
int ranks[MAX_N+1];
int teamSize[MAX_TEAM+1];

void init(){
    for(int i=0;i<=MAX_TEAM;i++){
        teams[i].clear();
        teamSize[i] = 0;
    }
}

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.first.first < b.first.first)
        return true;
    else if(a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return false;
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int test_case=0; test_case<T; test_case++){
        init();

        int N;
        scanf("%d",&N);

        for(int i=1;i<=N;i++){
            scanf("%d",&ranks[i]);

            teamSize[ranks[i]]++;
        }

        int score = 1;
        for(int i=1;i<=N;i++){
            if(teamSize[ranks[i]] < 6)
                continue;

            if(teams[ranks[i]].size() < 5)
                teams[ranks[i]].push_back(score);
            score++;
        }

        vector<pair<pair<int,int>,int> > vec;
        for(int i=1;i<=MAX_TEAM;i++){
            if(teams[i].size() < 5)
                continue;

            // sum
            int sum = 0;
            for(int j=0;j<4;j++)
                sum += teams[i][j];
            vec.push_back(make_pair(make_pair(sum,teams[i][4]),i));
        }

        sort(vec.begin(),vec.end(),comp);

        printf("%d\n",vec[0].second);
    }
    return 0;
}