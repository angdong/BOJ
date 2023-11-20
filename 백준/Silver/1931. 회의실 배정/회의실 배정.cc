#include<iostream>
#include<algorithm>

using namespace std;

int N;
pair<int, int> arr[100005];
#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i].Y;
        cin >> arr[i].X;
    }
    sort(arr, arr+N);
    
    int cnt=0;
    int t=0;

    for(int i=0; i<N; i++){
        if(t > arr[i].Y) continue;
        // 시작시간이 t 이후임
        cnt++;
        t = arr[i].X;
    }
    cout << cnt;
}