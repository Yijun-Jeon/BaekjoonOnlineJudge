#include <stdio.h>
#include <utility>

#define MAX_N 26

using namespace std;

int N;
pair<char,char> tree[MAX_N+1];

void preOrder(char node){
    if(node == '.')
        return;
    
    printf("%c",node);
    preOrder(tree[node-'A'].first);
    preOrder(tree[node-'A'].second);
}

void inOrder(char node){
    if(node == '.')
        return;
    
    inOrder(tree[node-'A'].first);
    printf("%c",node);
    inOrder(tree[node-'A'].second);
}

void postOrder(char node){
    if(node == '.')
        return;
    
    postOrder(tree[node-'A'].first);
    postOrder(tree[node-'A'].second);
    printf("%c",node);
}

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        getchar();
        char n; scanf("%c",&n);
        getchar();
        char left; scanf("%c",&left);
        getchar();
        char right; scanf("%c",&right);

        tree[n-'A'].first = left;
        tree[n-'A'].second = right;
    }

    preOrder('A'); printf("\n");
    inOrder('A'); printf("\n");
    postOrder('A'); printf("\n");
    return 0;
}