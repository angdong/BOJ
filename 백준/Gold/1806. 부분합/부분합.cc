#include<iostream>

using namespace std;
int N, S;
int arr[100004];
int min_len = 100005;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> arr[i];

    int partial_sum=0;
    int en=0;
    bool isvalid=false;
    for(int st=0; st<N; st++){
        if(st>0) partial_sum -= arr[st-1];
        while(partial_sum<S && en<N){
            partial_sum += arr[en++];
        }
        if(partial_sum<S) break;
        isvalid = true;
        min_len = min(min_len, en-st);
    }
    if(!isvalid) cout << 0;
    if(isvalid) cout << min_len;
    
}