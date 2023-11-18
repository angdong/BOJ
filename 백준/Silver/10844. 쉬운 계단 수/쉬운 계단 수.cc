#include<iostream>

using namespace std;

long long arr[105][10];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<10; i++){
        arr[1][i] = 1;
    }
    arr[1][0] = 0;
    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k: {j-1, j+1}){
                if(k<0 || k>9) continue;
                arr[i][j] += arr[i-1][k];
            }
            arr[i][j] %= 1000000000;
        }
    }
    long long tmp=0;
    for(int i=0; i<10; i++){
        tmp += arr[N][i];
    }
    cout << tmp%1000000000;
}