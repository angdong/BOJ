#include<iostream>

using namespace std;

int N;
int K;
int arr[15];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int numb=0;
    int idx=0;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(arr[i] <= K) idx = i;
    }
    while(K>0){
        if(arr[idx] > K) idx--;
        else{
            numb++;
            K-= arr[idx];
        }
    }
    cout << numb;
}