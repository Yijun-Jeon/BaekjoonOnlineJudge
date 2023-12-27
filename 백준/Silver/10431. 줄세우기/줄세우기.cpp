#include <stdio.h>
#include <cstring>

using namespace std;

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int test_case=0; test_case<T; test_case++){
        int P;
        scanf("%d",&P);

        int students[20];
        for(int i=0;i<20;i++)
            scanf("%d",&students[i]);

        int count = 0;
        int result[20];
        memset(result,0,sizeof(result));
        for(int i=0;i<20;i++){
            for(int j=0;j<i;j++){
                if(students[i] < result[j]){
                    for(int k=i; k>j; k--){
                        result[k] = result[k-1];
                        count++;
                    }
                    result[j] = students[i];
                    break;
                }
            }
            if(result[i] == 0)
                result[i] = students[i];
        }

        printf("%d %d\n",P,count);
    }
    return 0;
}