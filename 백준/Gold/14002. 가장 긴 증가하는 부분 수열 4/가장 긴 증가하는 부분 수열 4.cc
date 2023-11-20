#include<iostream>
#include<vector>

using namespace std;

int arr[1005];
int N;
vector<int> v[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    v[1].push_back(arr[1]);
    for(int i=2; i<=N; i++){
        for(int j=1; j<i; j++){
            if(arr[j] < arr[i]){
                // 증가하는 부분 수열임
                if(v[j].size() > v[i].size()){
                    // 더 큰 증가하는 부분 수열임
                    v[i].clear();
                    for(auto a: v[j])
                        v[i].push_back(a);
                }
            }
        }
        v[i].push_back(arr[i]);
    }
    int max_idx=1;
    for(int i=2; i<=N; i++){
        if(v[i].size() > v[max_idx].size()) max_idx = i;
    }
    cout << v[max_idx].size() << "\n";
    for(auto a: v[max_idx]) cout << a << " ";
    // 가장 긴 증가하는 부분 수열의 길이 출력 및 그러한 수열 출력하기33
}