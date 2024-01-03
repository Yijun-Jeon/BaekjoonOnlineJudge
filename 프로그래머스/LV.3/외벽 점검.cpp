#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 200

using namespace std;

int map[MAX_N];

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size()+1;
    
    int total = weak.size();
    sort(dist.begin(),dist.end(),greater<int>());
    
    for(int i=0;i<total;i++){
        do{
            // 초기화
            for(int j=0;j<total;j++)
                map[weak[j]] = 1;

            int pos = weak[i];
            int todo = total;

            int idx = 0;
            int cando = dist[idx++];

            while(todo && idx < answer){
                // 한 친구 모두 소모
                if(cando == -1){
                    cando = dist[idx++];

                    // 모든 친구 소모
                    if(idx == dist.size() + 1)
                        break;

                    // 다음 취약지점에서 출발시킴
                    while(map[pos] == 0)
                        pos = (pos+n-1) % n;
                }

                // 취약지점
                if(map[pos] == 1){
                    map[pos] = 0;
                    todo--;
                }

                // 반시계방향 이동
                pos = (pos+n-1) % n;
                cando--;
            }

            answer = min(answer,idx);
        }while(next_permutation(dist.begin(),dist.end()));
    }
    
    return answer == dist.size() + 1 ? -1 : answer;
}