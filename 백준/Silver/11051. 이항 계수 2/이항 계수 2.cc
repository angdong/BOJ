#include<iostream>
using namespace std;

int comb[1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for(int i=1; i<=1000; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j=1; j<i; j++){
            // 2C1 -> 1C0 + 1C1
            // 4C2 -> 3C1 + 3C2
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % 10007;
        }
    }
    cout << comb[N][K];
}