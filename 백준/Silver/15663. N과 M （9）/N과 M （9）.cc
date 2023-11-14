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
    int tmp= -1;
    for(int i=0; i<N; i++){
        if(tmp==arr[i]) continue;
        if(already[i]) continue;
        tmp = arr[i];
        already[i] = true;
        ans[n] = arr[i];
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