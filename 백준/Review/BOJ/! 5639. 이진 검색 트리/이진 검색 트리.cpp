#include <iostream>

#define MAX_N 10000

using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

int nodeCnt = -1;
Node nodes[MAX_N];

void Push(Node* node, int key){
    if(key < node->key){
        if(node->left == NULL){
            node->left = &nodes[nodeCnt];
            return;
        }else Push(node->left,key);
    }else{
        if(node->right == NULL){
            node->right = &nodes[nodeCnt];
            return;
        }else Push(node->right,key);
    }
}

void PostOrder(Node* node){
    if(node == NULL)
        return;

    PostOrder(node->left);
    PostOrder(node->right);
    printf("%d\n",node->key);
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int key;
    while(cin >> key){
        nodes[++nodeCnt].key = key;
        nodes[nodeCnt].left = NULL;
        nodes[nodeCnt].right = NULL;
        if(nodeCnt == 0)
            continue;

        Push(&nodes[0],key);
    }

    PostOrder(&nodes[0]);
    return 0;
}