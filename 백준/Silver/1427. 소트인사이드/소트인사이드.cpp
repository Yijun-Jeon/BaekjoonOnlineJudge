#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    string N;
    cin >> N;

    int len = N.length();
    int nums[len];
    for(int i=0;i<len;i++)
        nums[i] = N[i] - '0';

    sort(nums,nums+len,greater<int>());
    for(int i=0;i<len;i++)
        cout << nums[i];
    cout << endl;
    return 0;
}