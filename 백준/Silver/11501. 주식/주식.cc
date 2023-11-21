#include<iostream>

using namespace std;

long long arr[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        for(int i=0; i<N; i++){
            cin >> arr[i];
        }
        long long answer=0;
        long long last=arr[N-1];
        for(int i=N-2; i>=0; i--){
            if(arr[i] > last) last = arr[i];
            else answer += (last - arr[i]);
        }
        cout << answer << "\n";
    }
}