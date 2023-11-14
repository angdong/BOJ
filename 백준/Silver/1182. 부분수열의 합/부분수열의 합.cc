#include<iostream>

using namespace std;

int cnt;
int arr[20];
int ans[20];
int N, S;

void func(int n, int first){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += ans[i];
    }
    if(sum == S && n > 0){
        // for(int i=0; i<n; i++){
        //     cout << ans[i] << " ";
        // }
        // cout << "\n";    
        cnt++;
    }

    for(int i=first; i<N; i++){
        ans[n] = arr[i];
        func(n+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> arr[i];

    func(0, 0);
    cout << cnt;
}