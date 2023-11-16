// 첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

// 둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다.
// 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.
#include<iostream>

using namespace std;

int arr1[1000000];
int arr2[1000000];
int ans[2000000];
int N, M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr1[i];   
    } 
    for(int i=0; i<M; i++){
        cin >> arr2[i];   
    }
    int lindex = 0;
    int rindex = 0;
    for(int i=0; i<N+M; i++){
        if(lindex==N) ans[i] = arr2[rindex++];
        else if(rindex==M) ans[i] = arr1[lindex++];
        else if(arr1[lindex] <= arr2[rindex]) ans[i] = arr1[lindex++];
        else ans[i] = arr2[rindex++];
    }
    for(int i=0; i<N+M; i++){
        cout << ans[i] << " ";
    }
}