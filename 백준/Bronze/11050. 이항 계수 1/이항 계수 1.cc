#include<iostream>
using namespace std;


int facto(int n){
    if(n==0) return 1;
    for(int i=n-1; i>1; i--){
        n*=i;
    }
    return n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    cout << facto(N) / (facto(K) * facto(N-K));
}