#include<iostream>

using namespace std;

int N;
int arr[35];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    

    arr[2] = 3;
    for(int i=4; i<=N; i+=2){
        arr[i] += 3*arr[i-2];
        int idx=i-4;
        while(idx>0){
            arr[i] += arr[idx] * 2;
            idx-=2;
        }
        arr[i] += 2;
    }
    cout << arr[N];
}