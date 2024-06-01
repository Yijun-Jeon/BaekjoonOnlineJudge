#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 200
#define MAX_F 9

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = MAX_F;
    

    do{
        for(int i=0;i<weak.size();i++){
            int weakCnt = weak.size();
            int distIdx = 0;
            int weakIdx = i;
            while(true){
                if(distIdx > answer)
                    break;
                if(++distIdx > dist.size() || weakCnt == 0)
                    break;
                
                int now = weak[weakIdx];
                for(int j=now; j <= now+dist[distIdx-1]; j++){
                    if(weakCnt == 0)
                        break;
                    if(j%n == weak[weakIdx]){
                        weakCnt--;
                        weakIdx = (weakIdx+1) % weak.size();
                    }
                }      
            }
            if(weakCnt == 0)
                answer = min(answer,distIdx-1);
        }        
    }while(next_permutation(dist.begin(),dist.end()));

    
    if(answer == MAX_F)
        answer = -1;
    return answer;
}