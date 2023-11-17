#include<iostream>

using namespace std;

int arr[1000001];
int tmp[1000001];

int N;


void merge(int st, int ed){
    int mid = (st+ed)/2;
    int lindex = st;
    int rindex = mid;
    for(int i=st; i<ed; i++){
        if(lindex==mid) tmp[i] = arr[rindex++];
        else if(rindex==ed) tmp[i] = arr[lindex++];
        else if(arr[lindex] <= arr[rindex]) tmp[i] = arr[lindex++];
        else tmp[i] = arr[rindex++];
    }
    for(int i=st; i<ed; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int ed){
    if(st>=ed-1) return;
    int mid = (st+ed)/2;
    
    merge_sort(st, mid);
    merge_sort(mid, ed);
    merge(st, ed);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    merge_sort(0, N);

    for(int i=0; i<N; i++) cout << arr[i] << "\n";
}