#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr1[52];
int arr2[52];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr1[i];
    }
    for(int i=0; i<N; i++){
        cin >> arr2[i];
    }
    sort(arr1, arr1+N);
    sort(arr2, arr2+N);
    int res=0;
    for(int i=0; i<N; i++){
        res += arr1[N-1-i] * arr2[i];
    }
    cout << res;
}