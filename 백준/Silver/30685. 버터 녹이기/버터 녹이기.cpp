#include <iostream>
#include <algorithm>
#include <utility>

#define MAX_N 300000
#define MAX_TIME 2e9

using namespace std;

int N;
pair<int,int> map[MAX_N];

int binarySearch(int left, int right){
    while(left <= right){
        int mid = (left + right)/2;

        int prev = map[0].first + min(map[0].second,mid);

        bool pass = true;
        for(int i=1;i<N && pass;i++){
            if(map[i].first - min(map[i].second,mid) <= prev)
                pass = false;
            prev = map[i].first + min(map[i].second,mid);
        }

        if(pass)
            left = mid+1;
        else
            right = mid-1;
    }
    return left-1;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> map[i].first >> map[i].second;
        map[i].second /= 2;
    }

    sort(&map[0],&map[N]);

    int result = binarySearch(0,1e9);
    if(result == 1e9)
        cout << "forever" << '\n';
    else
        cout << result << '\n';
    return 0;
}