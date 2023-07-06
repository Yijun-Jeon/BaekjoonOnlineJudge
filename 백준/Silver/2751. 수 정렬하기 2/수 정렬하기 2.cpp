#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int nums[N];
    for(int i=0;i<N;i++)
        cin >> nums[i];

    sort(nums,nums+N);
    for(int i=0;i<N;i++)
        cout << nums[i] << '\n';
    
    return 0;
}