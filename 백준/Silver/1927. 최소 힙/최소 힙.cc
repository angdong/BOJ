#include<iostream>

using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
    heap[++sz] = x;
    int idx=sz;
    while(idx>1 && heap[idx] < heap[idx/2]){
        swap(heap[idx], heap[idx/2]);
        idx /= 2;
    }
}

int top(){
    return heap[1];
}

void pop(){
    heap[1] = heap[sz--];
    int idx=1;
    while(2*idx<=sz){
        int new_idx = 2*idx;
        if(2*idx+1<=sz && heap[2*idx+1] < heap[2*idx]) new_idx = 2*idx+1;

        if(heap[idx] > heap[new_idx]){
            swap(heap[idx], heap[new_idx]);
            idx = new_idx;
        }
        else{
            break;
        }
    }
}

int N;
int x;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--){
        cin >> x;
        if(x>0){
            push(x);
        }
        else{
            if(sz==0){
                cout << 0 << "\n";
            }
            else{
                cout << top() << "\n";
                pop();
            }
        }
    }
}