#include<iostream>

using namespace std;

long long ans[1005];

int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ans[1] = 1;
    ans[2] = 2;
    for(int i=3; i<=N; i++){
        ans[i] = (ans[i-1] % 10007 + ans[i-2] %10007) % 10007;
    }
    cout << ans[N] % 10007;
}