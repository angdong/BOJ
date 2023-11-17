#include<iostream>

using namespace std;

int arr[1000005];
int main(){
    int X;
    cin >> X;
    // 3나눠짐 -> 3으로 나눔
    // 2나눠짐 -> 2로 나눔
    // 1뺌
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i=1; i<X; i++){
        for(int j: {2*i, 3*i, i+1}){
            // if(arr[j] != 0 && j == X){
            //     cout << arr[j];
            //     return 0;
            // }
            if(j > X) continue;
            if(arr[j] ==0 || arr[j] > arr[i]+1){
                arr[j] = arr[i]+1;
            }
        }
    }
    cout << arr[X];
}