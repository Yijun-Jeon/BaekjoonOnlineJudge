#include <vector>
#include <queue>

#define MAX_N 200000

using namespace std;

bool remain[MAX_N+1];
int N;
priority_queue<pair<int,int> > pq;

int solution(vector<int> food_times, long long k) {
    N = food_times.size();
    for(int i=1;i<=N;i++){
        remain[i] = true;
        pq.push({-food_times[i-1],i});
    }
    
    int cycle = 0;
    while(!pq.empty() && k >= pq.size()){
        int top = -pq.top().first;
        if((top - cycle) > k / pq.size()){
            k -= (k / pq.size()) * pq.size();
            cycle += k / pq.size(); 
        }else{
            k -= (top-cycle) * pq.size();
            cycle = top;
        
            while(!pq.empty() && cycle == -pq.top().first){
                remain[pq.top().second] = false;
                pq.pop();        
            }
                
        }
    }

    int answer;
    if(pq.empty())
        answer = -1;
    else{
        for(int i=1;i<=N;i++){
            if(remain[i]){
                answer = i;
                break;
            }    
        }
        while(k){
            if(remain[++answer])
                k--;
        }
    }            
    
    return answer;
}