#include<iostream>

using namespace std;

int N;
int arr[1005];
int ans[1005];
int max_cnt=1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    fill(ans+1, ans+N+1, 1);
    for(int i=1; i<N; i++){
        for(int j=i+1; j<=N; j++){
            if(arr[j] > arr[i]){
                if(ans[j] < ans[i] + 1){
                    ans[j] = ans[i]+1;
                    if(max_cnt < ans[j]) max_cnt = ans[j];
                }
            }
        }
    }
    cout << max_cnt;
}