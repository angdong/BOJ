#include<iostream>
#include<algorithm>

using namespace std;


int N, M;
int ans[8];
int arr[8];
bool already[8];

void func(int n){
    if(n==M){
        for(int i=0; i< M; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<N; i++){
        if(already[i]) continue;
        ans[n] = arr[i];
        already[i] = true;
        func(n+1);
        already[i] = false;
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    func(0);
}