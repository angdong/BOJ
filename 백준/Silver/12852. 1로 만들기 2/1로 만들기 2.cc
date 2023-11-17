#include<iostream>

using namespace std;

#define X first
#define Y second

pair<int, int> arr[1000005];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    // 부모 idx, 연산 횟수
    arr[1] = {0, 0};
    arr[2] = {1, 1};
    arr[3] = {1, 1};


    for(int i=1; i<=N; i++){
        for(int t: {i+1, 2*i, 3*i}){
            if(t > N) continue;
            if(arr[t].Y == 0 || arr[t].Y > arr[i].Y + 1){
                arr[t] = {i, arr[i].Y+1};
            }
        }
    }
    cout << arr[N].Y << "\n";
    int idx = N;
    while(idx > 0){
        cout << idx << " ";
        idx = arr[idx].X;
    }

}