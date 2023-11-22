#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int arr[1005];
vector<int> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i <N; i++) cin >> arr[i];

    for(int i=0; i<N; i++)
    for(int j=i; j<N; j++){
        v.push_back(arr[i]+arr[j]);
    }
    sort(arr, arr+N);
    sort(v.begin(), v.end());
    for(int i=N-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(binary_search(v.begin(), v.end(), arr[i]-arr[j])){
                cout << arr[i];
                return 0;
            }
        }
    }

}