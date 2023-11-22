#include<iostream>
#include<algorithm>

using namespace std;

int K, N;
int arr[10005];

int calc_line_numb(int n){
    int tmp=0;
    for(int i=0; i<K; i++){
        tmp+= arr[i]/n;
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for(int i=0; i<K; i++) cin >> arr[i];
    long long st=1;
    long long ed=*max_element(arr, arr+K);
    while(st<ed){
        long long mid = (st+ed+1)/2;
        int numb = calc_line_numb(mid);
        if(numb < N){
            // 개수 딸림 -> 랜선 길이 줄여야 함
            ed = mid-1;
        }
        else{
            // 개수 같거나 많음 -> 랜선 길이 늘려야 함
            // st를 mid로
            st = mid;
        }
    }
    cout << st;
}