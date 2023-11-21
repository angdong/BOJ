#include<iostream>
#include<algorithm>

using namespace std;

int N;
pair<int, int> arr[400004];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<2*N; i+=2){
        int st, ed;
        cin >> st>> ed;
        arr[i] = {st, 1};
        arr[i+1] = {ed, -1};
    }
    sort(arr, arr+2*N);
    int max_cnt=0;
    int now_cnt=0;
    for(int i=0; i<2*N; i++){
        now_cnt += arr[i].second;
        max_cnt = max(max_cnt, now_cnt);
    }
    cout << max_cnt;
    // 문제의 답 -> 가장 많은 수업이 열리는 시각의 수업의 개수!
    
}