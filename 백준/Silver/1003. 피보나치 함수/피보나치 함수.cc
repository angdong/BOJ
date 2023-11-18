#include<iostream>

using namespace std;

pair<int, int> ans[50];
#define X first
#define Y second

int T;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    ans[0] = {1, 0};
    ans[1] = {0, 1};
    for(int i=2; i<=40; i++){
        ans[i] = {ans[i-1].X + ans[i-2].X, ans[i-1].Y + ans[i-2].Y};
    }
    //0] 1 0
    //1] 0 1
    //2] 1 1
    //3] (2 1) -> (1 0) 1 2

    while(T--){
        cin >> N;
        cout << ans[N].X << " " << ans[N].Y << "\n";
    }
}