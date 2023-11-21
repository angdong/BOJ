#include<iostream>
#include<algorithm>

using namespace std;

int arr[1005];
int ans[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            ans[i] += arr[j];
        }
    }
    int tmp=0;
    for(int i=0; i<N; i++) tmp+= ans[i];
    cout << tmp;
}