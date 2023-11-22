#include<iostream>
#include<algorithm>

int N;

using namespace std;
int arr[1000004];
int arr2[1000004];

int ans[1000004];

int binary_search(int target, int len){
    int st=0;
    int en=len-1;
    while(st<=en){
        int mid=(st+en)/2;
        if(target==ans[mid]) return mid;
        else if(target<ans[mid]) en=mid-1;
        else st=mid+1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    sort(arr, arr+N);
    int now_val = arr[0];
    ans[0]=arr[0];
    int array_numb=1;
    for(int i=1; i<N; i++){
        if(arr[i] == now_val) continue;
        else{
            now_val = arr[i];
            ans[array_numb++] = arr[i];
        }
    }
    for(int i=0; i<N; i++){
        cout << binary_search(arr2[i], array_numb) << " ";
    }
}