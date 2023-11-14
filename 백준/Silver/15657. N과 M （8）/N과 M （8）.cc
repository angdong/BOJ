#include<iostream>
#include<algorithm>

using namespace std;


int N, M;
int ans[8];
int arr[8];

bool is_not_valid[8][100000];

void func(int n, int start){
    if(n==M){
        for(int i=0; i< M; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=start; i<N; i++){
        if(is_not_valid[n][arr[i]]) continue;
        ans[n] = arr[i];
        is_not_valid[n][arr[i]] = true;
        func(n+1, i);
    }
    for(int i=start; i<N; i++){
        is_not_valid[n][arr[i]] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    int i=0;
    int val = -1;
    // for(int i=0; i<N; i++) cout << arr[i] << " ";

    func(0, 0);
}