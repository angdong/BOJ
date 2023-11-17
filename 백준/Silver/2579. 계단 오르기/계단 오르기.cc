#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[301];
int ans[301];


#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    ans[0] = arr[0];
    if(N>1){
        ans[1] =arr[0] + arr[1];
    }
    if(N>2){
        ans[2] = max(arr[0], arr[1]) + arr[2];
    }
    // 2칸 올랐냐 vs 한칸 올랐냐(2칸->1칸만 가능)
    // 연속된 세개의 계단 밟을 수 없음
    for(int i=3; i<N; i++){
        ans[i] = max(ans[i-2], ans[i-3] + arr[i-1]) + arr[i];
    }
    // for(int i=0; i<N; i++){
    //     cout << ans[i] << " ";
    // }
    // cout << "\n";
    // for(int i=0; i<N; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    cout << ans[N-1];

    //[] [n-2] [n-1] [n]
    // max([n-2] + [n-1], [n-1])
    // 한 칸 전 -> 1 한개 적립
    // 두 칸 전 -> 1 두개 적립(다음거는 1못함)
    // 두 칸 전 -> +2 0개 적립
}