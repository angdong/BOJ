#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int arr[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];

    sort(arr, arr+N);

    int min_val = INT32_MAX;
    int upindex=0;
    int downindex=0;
    while(upindex<N-1){
        // 크기비교하기
        int diff =arr[downindex] - arr[upindex];
        if(diff >= M){
            // M 이상이다
            if(diff < min_val) min_val = diff;
            upindex++;
        }
        else{
            // M 보다 작다 -> downindex 증가시키기
            if(downindex==N-1) break;
            else downindex++;
        }
    }
    cout<<min_val;
}