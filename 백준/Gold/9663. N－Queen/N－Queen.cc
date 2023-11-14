#include<iostream>
#include<cstdlib>

using namespace std;

bool y_can[15];
pair<int, int> n_queen[15];
int N;
int ans;

#define X first
#define Y second

bool check(int n, int i, int j){
    if(!y_can[j]) return false;
    for(int t=0; t<n; t++){
        if(abs(n_queen[t].X - i) == abs(n_queen[t].Y - j)) return false;
    }
    return true;
}

void func(int n, int first_val){
    if(n==N){
        ans++;
        return;
    }
    for(int j=0; j<N; j++){
        if(check(n, first_val, j)){
            n_queen[n++] = {first_val, j};
            y_can[j] = false;
            func(n, first_val+1);
            n--;
            // x_can[i] = true;
            y_can[j] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(y_can, y_can+15, 1);

    func(0, 0);

    cout << ans;
}