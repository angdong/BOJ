#include<iostream>
#include<algorithm>

using namespace std;

int arr[500002];
int N, M;

int lower_idx(int target){
    int len = N;
    int st = 0;
    int en =len;
    while(st < en){
        int mid = (st+en)/2;
        if(arr[mid] >= target) en =mid;
        else st = mid+1;
    }
    return st;
}

int upper_idx(int target){
    int len =N;
    int en=len;
    int st=0;
    while(st<en){
        int mid=(st+en)/2;
        if(arr[mid] > target) en=mid;
        else st=mid+1;
    }
    return st;
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
        cout << upper_idx(target) - lower_idx(target) << "\n";
    }
}