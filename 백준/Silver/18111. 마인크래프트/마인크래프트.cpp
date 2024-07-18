#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 500
#define MAX_H 128000000

using namespace std;

int N,M,B;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> B;

    int minH = MAX_H, maxH = 0;
    vector<int> map;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int block;
            cin >> block;

            map.push_back(block);

            minH = min(minH,block);
            maxH = max(maxH,block);
        }
    }

    sort(map.begin(),map.end(),greater<int>());

    pair<int,int> result = make_pair(MAX_H,-1);
    for(int h=minH;h<=maxH;h++){
        int b = B;
        int time = 0;
        for(int i=0;i<map.size();i++){
            int diff = map[i] - h;
            
            if(diff >= 0){
                time += 2 * diff;
                b += diff;
            }else{
                if(-diff > b){
                    time = MAX_H;
                    break;
                }else{
                    time += -diff;
                    b -= -diff;
                }
            }
        }

        if(time < result.first)
            result = make_pair(time,h);
        else if(time == result.first){
            result.second = h;
        }
    }

    cout << result.first << " " << result.second << '\n';
    return 0;
}