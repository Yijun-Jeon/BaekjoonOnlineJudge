#include<iostream>
#include<algorithm>
#define MAX_K 1000000

#define parent(i) (i >> 1)
#define left(i) (i << 1)
#define right(i) (i << 1 | 1)

using namespace std;

int arr[MAX_K];
int tree[MAX_K];

void buildTree(int i, int start, int end){
    // leaf 노드가 들어갈 위치
    if(start == end){
        tree[i] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(left(i),start,mid);
    buildTree(right(i),mid+1,end);

    // sum tree
    tree[i] = tree[left(i)] + tree[right(i)];
    // max tree
    tree[i] = max(tree[left(i)], tree[right(i)]);
    // min tree
    tree[i] = min(tree[left(i)], tree[right(i)]);
}

int query(int i, int start, int end, int left, int right){
    // 유효한 범위가 아니므로 종료(무의미한 값 반환)
    if(start > right || end < left){
        // sum tree
        return 0;
        // max tree
        return 0;
        // min tree
        return MAX_K;
    }

    // i가 left ~ right를 모두 포함하는 범위이므로 i값 반환 
    if(left <= start && end <= right)
        return tree[i];

    int mid = (start+end) / 2;

    int q1 = query(left(i), start, mid, left, right);
    int q2 = query(right(i),mid+1, end, left, right);

    // sum tree
    int result = q1+q2;
    // max tree
    int result = max(q1,q2);
    // min tree
    int result =  min(q1,q2);
    
    return result;
}

void updateSumTree(int i, int index ,int start, int end, int diff){
    // 유효한 범위가 아니므로 종료
    if(index < start || index > end)
        return;

    // sum tree
    tree[i] += diff;

    if(start != end){
        int mid = (start + end) / 2;
        updateSumTree(left(i), index, start, mid, diff);
        updateSumTree(right(i), index, mid+1, end, diff);
    }
}

int updateMaxMinTree(int i, int index ,int start, int end, int value){
    // 유효한 범위가 아니므로 종료
    if(index < start || index > end)
        return tree[i];

    if(start == end)
        return tree[i] = value;

    int mid = (start + end) / 2;
    int left = updateMaxMinTree(left(i), index, start, mid, value);
    int right = updateMaxMinTree(right(i), index, mid+1, end, value);

    // max tree
    return tree[i] = max(left,right);
    // min tree
    return tree[i] = min(left,right);
}


int main(void){
    int len;
    cin >> len;

    for(int i=0;i<len;i++)
        cin >> arr[i];

    memset(tree,0,sizeof(int)*len*4);
    buildTree(1,0,len-1);

    while(1){
        int cmd;
        cin >> cmd;

        if(cmd == -1)
            break;

        if(cmd == 1){
            int left, right;
            cin >> left >> right;

            cout << query(1,0,len-1,left-1,right-1) << endl;
        }else if(cmd == 2){
            int i, value;
            cin >> i >> value;

            int diff;

            // sum tree
            diff = value - arr[i];
            arr[i] = value;

            updateSumTree(1,i,0,len-1,diff);

            // max & min tree            
            arr[i] = value;

            updateMaxMinTree(1,i,0,len-1,value);
        }else if(cmd == 3){
            for(int i=1;i<4*len;i++)
                cout << tree[i] << " ";
            cout << endl;
        }
    }
    return 0;
}