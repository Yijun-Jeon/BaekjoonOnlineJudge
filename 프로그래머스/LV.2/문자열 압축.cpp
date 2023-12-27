#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    int size = 0;
    while(++size <= s.size()/2){
        string last, now;
        int dup = 1;
        int len = 0;
        
        int idx = 0;
        while(idx < s.size()){
            if(now.size() < size){
                now += s[idx++];
                len++;
            }
            else{
                if(now == last){
                    dup++;
                    len -= size;
                }
                else{
                    if(dup > 1)
                        len += to_string(dup).size();
                    dup = 1;
                }
                last = now;
                now = "";
            }
        }
        
        
        if(now == last){
            len -= size;
            dup++;
        }
        
        if(dup > 1)
            len += to_string(dup).size();
        
        answer = len < answer ? len : answer;
    }
    
    return answer;
}