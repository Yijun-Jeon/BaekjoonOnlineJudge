#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N,M;
    cin >> N;

    vector<int> cards(N);
    for(int i=0;i<N;i++)
        cin >> cards[i];
    sort(cards.begin(),cards.end());

    cin >> M;
    vector<int> nums(M);
    for(int i=0;i<M;i++){
        int temp;
        cin >> temp;
        int idx = lower_bound(cards.begin(),cards.end(),temp) - cards.begin();
        nums[i] = cards[idx] == temp && idx < M;
    }

    for(int i=0;i<M;i++)
        cout << nums[i] << ' ';
    cout << '\n';
    return 0;
}