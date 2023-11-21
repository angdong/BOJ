#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
long long arr[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin>>arr[i];

    while(m--){
        sort(arr, arr+n);
        long long tmp = arr[0] + arr[1];
        arr[0] = tmp;
        arr[1] = tmp;
    }
    long long res=0;
    for(int i=0; i<n; i++) res+= arr[i];
    cout << res;
}