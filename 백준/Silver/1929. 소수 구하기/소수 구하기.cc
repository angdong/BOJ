#include<iostream>
#include<vector>

using namespace std;
int M, N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    vector<bool> check(N+1, true);
    check[1] = false;
    for(int i=2; i*i<=N; i++){
        if(!check[i]) continue;
        for(int j=i*i; j <= N; j+=i)
            check[j] = false;
    }
    for(int i=M; i<=N; i++){
        if(check[i]) cout << i << "\n";
    }
}