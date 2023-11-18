#include<iostream>

using namespace std;

int ans_odd[2005][2005];
int ans_even[2005][2005];
int arr[2005];
int N;
int M;
int S, E;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=N; i++){
        // 1 2 [3] 2 1
        ans_odd[i][i] = 1;
        for(int j=1; j<N; j++){
            int lindex=i-j;
            int rindex=i+j;
            if(lindex < 1 || rindex > N) break;
            if(arr[lindex] == arr[rindex]) ans_odd[i][rindex] = 1;
            else break;   
        }
        // 1 2 [3] 3 2 1
        for(int j=0; j<N; j++){
            int lindex=i-j;
            int rindex=i+j+1;
            if(lindex < 1 || rindex > N) break;
            if(arr[lindex] == arr[rindex]) ans_even[i][rindex] = 1;
            else break;
        }
    }
    cin >> M;
    while(M--){
        cin >> S>>E;
        // check palindrome
        int mid = (E+S)/2;
        bool even = (E-S+1) % 2 == 0;
        if(even){
            cout << ans_even[mid][E];
        }
        else
            cout << ans_odd[mid][E];
        cout << "\n";
    }
}