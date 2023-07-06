#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void)
{
    int nums[5];
    for(int i=0;i<5;i++)
        cin >> nums[i];

    sort(nums,nums+5);

    cout << accumulate(nums,nums+5,0) / 5 << endl;
    cout << nums[5/2] << endl;
    return 0;
}