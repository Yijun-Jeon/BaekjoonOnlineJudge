#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 200000

using namespace std;

struct Food{
    long long time;
    int idx;
    
    bool operator()(const Food* below, const Food* above) const{
        if(below->time > above->time)
            return true;
        else if(below->time == above->time)
            return below->idx < above->idx;
        return false;
    }
};

Food foods[MAX_N+1];
int idx = 0;
priority_queue<Food*, vector<Food*>, Food> pq;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
        
    long long total = 0;
    for(int i=0;i<food_times.size();i++){
        foods[i+1].time = food_times[i];
        foods[i+1].idx = i+1;
        
        pq.push(&foods[i+1]);
        total += food_times[i];
    }
    
    if(total <= k)
        return -1;
    
    long long sum = 0;
    int prev = 0;
    while(sum + (pq.top()->time - prev) * pq.size() <= k){
        Food now = *pq.top();
        sum += (now.time - prev) * pq.size();
        prev = now.time;
        pq.pop();
    }
    
    vector<int> remain;
    while(!pq.empty()){
        remain.push_back(pq.top()->idx);
        pq.pop();
    }
    
    sort(remain.begin(),remain.end());
    
    answer = remain[(k-sum) % remain.size()];
    return answer;
}