#include<iostream>

using namespace std;

int N;
int arr[1005];
int ans[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    ans[1] = arr[1];
    for(int i=2; i<=N; i++){
        ans[i] = arr[i];
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j] && ans[i] < arr[i] + ans[j]) ans[i] = arr[i] + ans[j];
        }
        // dp[i] -> i번째 arr의 합이 가장 큰 증가하는 부분 수열
    }
    int max_val = 0;
    for(int i=1; i<=N; i++){
        if(ans[i] > max_val) max_val = ans[i];
        // cout << ans[i] << " ";
    }
    cout << max_val;
}