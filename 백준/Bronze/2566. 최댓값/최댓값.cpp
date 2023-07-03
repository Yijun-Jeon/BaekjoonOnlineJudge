#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int nums[81];

    for(int i=0;i<81;i++)
        cin >> nums[i];

    cout << *max_element(nums,nums+81)<<endl;
    int idx = max_element(nums,nums+81) - nums;
    cout << idx/9 + 1 << " " << idx%9 + 1 <<endl;
    return 0;
}