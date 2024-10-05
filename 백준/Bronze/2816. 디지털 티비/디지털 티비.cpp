#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100

using namespace std;

int N;
string channels[MAX_N];

int main(void)
{  
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0;i<N;i++)
        cin >> channels[i];

    int now = 0;
    vector<int> result;
    while(channels[now] != "KBS1"){
        result.push_back(1);
        now++;
    }
    while(now != 0){
        result.push_back(4);
        swap(channels[now-1],channels[now]);
        now--;
    }

    if(channels[1] != "KBS2"){
        while(channels[now] != "KBS2"){
            result.push_back(1);
            now++;
        }
        while(now != 1){
            result.push_back(4);
            swap(channels[now-1],channels[now]);
            now--;
        }
    }

    for(int i=0;i<result.size();i++)
        cout << result[i];
    cout << '\n';
    return 0;
}