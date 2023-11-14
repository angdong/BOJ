#include<iostream>

using namespace std;


int N, M;
int ans[8];

void func(int n, int start){
    if(n==M){
        for(int i=0; i< M; i++) cout << ans[i]+1 << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<N; i++){
        ans[n] = i;
        func(n+1, i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(0, 0);
}