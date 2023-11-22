#include<iostream>
#include<algorithm>

using namespace std;

int arr[100005];
int N, M;

int b_search(int target){
    int st=0;
    int en=N-1;
    while(st<=en){
        int mid = (st+en)/2;
        if(arr[mid] == target) return 1;
        else if(arr[mid] < target) st=mid+1;
        else en=mid-1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    cin >> M;
    sort(arr, arr+N);
    while(M--){
        int target;
        cin >> target;
        cout << b_search(target) << "\n";
    }
}