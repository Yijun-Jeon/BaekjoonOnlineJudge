#include<iostream>
#include<algorithm>

// 최소힙 구현 
struct PriorityQueue{
    #define MAX_SIZE 10000
    #define Data int
    #define NullData -1;
    #define parent(i) (i >> 1)
    #define left(i) (i << 1)
    #define right(i) (i << 1 | 1)

    int size = 0;
    Data heap[MAX_SIZE+1];

    void clear(){
        size = 0;
    }

    void push(pair<int,int> p){
        heap[++size] = p;
        int idx = size;
        while(idx > 1 && heap[idx] < heap[parent(idx)]){
            swap(heap[idx],heap[parent(idx)]);
            idx = parent(idx);
        }
    }

    void pop(){
        if(empty())
            return;

        heap[1] = heap[size--];
        int idx = 1;
        while(left(idx) <= size){
            if(left(idx) == size || heap[left(idx)] < heap[right(idx)]){
                if(heap[idx] > heap[left(idx)]){
                    swap(heap[idx],heap[left(idx)]);
                    idx = left(idx);
                }else break;
            }else{
                if(heap[idx] > heap[right(idx)]){
                    swap(heap[idx],heap[right(idx)]);
                    idx = right(idx);
                }else break;
            }
        }
    }

    bool empty(){
        return size == 0;
    }

    Data top(){
        if(empty())
            return NullData;
        return heap[1];
    }
};