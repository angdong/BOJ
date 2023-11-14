#include<iostream>
#include<algorithm>

using namespace std;


int N, M;
int ans[8];
int arr[8];

void func(int n, int start){
    if(n==M){
        for(int i=0; i< M; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=start; i<N; i++){
        ans[n] = arr[i];
        func(n+1, i+1);
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    func(0, 0);
}