#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 500

using namespace std;

pair<int,int> fails[MAX_N+2];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    sort(stages.begin(),stages.end());
    for(int i=0;i<(int)stages.size();i++){
        if(fails[stages[i]].first++ == 0)
            fails[stages[i]].second = (int)stages.size() - i;
    }
    
    vector<pair<double,int>> failVec;
    for(int i=1;i<=N;i++){
        if(fails[i].first == 0 || fails[i].second == 0)
            failVec.push_back({0,i});
        else
            failVec.push_back({(-(double)fails[i].first/fails[i].second),i});
    }
    sort(failVec.begin(),failVec.end());
    for(int i=0;i<(int)failVec.size();i++){
        answer.push_back(failVec[i].second);
    }
    return answer;
}