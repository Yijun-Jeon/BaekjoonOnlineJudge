#include <stdio.h>

using namespace std;

int main(void)
{
    int N,T,P;
    int size[6];

    scanf("%d",&N);
    for(int i=0;i<6;i++)
        scanf("%d",&size[i]);
    scanf("%d %d",&T,&P);

    int result = 0;
    for(int i=0;i<6;i++){
        if(size[i] == 0)
            continue;

        if(size[i] / T == 0)
            result++;
        else{
            result += size[i] / T;
            if(size[i] % T) result++;    
        }
    }
    printf("%d\n",result);
    printf("%d %d\n",N/P,N%P);
    return 0;
}