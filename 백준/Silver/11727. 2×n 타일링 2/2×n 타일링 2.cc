#include<iostream>

using namespace std;

int n;
long long arr[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr[1] = 1;
    arr[2] = 3;
    for(int i=3; i<=n; i++){
        arr[i] = arr[i-1] % 10007 + (2 * arr[i-2]) % 10007;
    }
    cout << arr[n] % 10007;
}