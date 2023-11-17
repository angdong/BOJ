#include<iostream>

using namespace std;

int arr[2000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        int tmp;
        cin >> tmp;
        arr[tmp+1000000]++;
    }
    for(int i=0; i<2000001; i++){
        while(arr[i]--){
            cout << i-1000000 << "\n";
        }
    }
}