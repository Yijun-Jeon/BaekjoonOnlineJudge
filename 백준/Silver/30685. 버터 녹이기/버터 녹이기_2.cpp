#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    pair<int,int> butters[N];
    int maxH = 0;
    for(int i=0;i<N;i++){
        cin >> butters[i].first >> butters[i].second;
        maxH = max(maxH,butters[i].second);
    }

    sort(&butters[0],&butters[N]);
    
    int left = 0, right = maxH;
    while(left<=right){
        int mid = (left+right)/2;
        
        bool valid = true;
        int prev = butters[0].first + min(butters[0].second/2,mid);
        for(int i=1;i<N && valid;i++){
            if(butters[i].first - min(butters[i].second/2,mid) <= prev)
                valid = false;
            prev = butters[i].first + min(butters[i].second/2,mid);
        }

        if(valid) left = mid+1;
        else right = mid-1;
    }
    if(left == maxH+1) cout << "forever" << '\n';
    else cout << left-1 << '\n';
    return 0;
}