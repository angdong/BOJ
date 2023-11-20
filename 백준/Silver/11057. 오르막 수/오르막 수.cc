// 오르막 수
#include<iostream>

using namespace std;

int N;
int dp[1005][10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(dp[1], dp[1] + 10, 1);
    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += (dp[i-1][k] % 10007);
            }
        }
    }
    int ans=0;
    for(int i=0; i<10; i++){
        ans += (dp[N][i] % 10007);
    }
    cout << ans % 10007;
}