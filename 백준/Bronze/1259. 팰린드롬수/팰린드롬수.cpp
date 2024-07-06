#include <stdio.h>
#include <cstring>

#define MAX_LEN 5

using namespace std;

int main(void)
{
    while(true){
        char num[MAX_LEN+1];
        scanf("%s",num);

        if(num[0] == '0')
            break;

        int left = 0, right = strlen(num)-1;
        while(left < right){
            if(num[left] != num[right])
                break;
            left++;
            right--;
        }

        if(left >= right) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}