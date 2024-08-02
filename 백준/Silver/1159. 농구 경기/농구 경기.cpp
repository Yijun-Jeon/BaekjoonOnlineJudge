#include <stdio.h>

#define MAX_ALPHA 26
#define MAX_LEN 30

using namespace std;

int alphas[MAX_ALPHA];

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        char name[MAX_LEN+1];
        scanf("%s",name);

        alphas[name[0]-'a']++;
    }

    bool surrender = true;
    for(int i=0;i<MAX_ALPHA;i++){
        if(alphas[i] >= 5){
            surrender = false;
            printf("%c",i+'a');
        }            
    }
    if(surrender) printf("PREDAJA");
    printf("\n");
    return 0;

}