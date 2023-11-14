#include<iostream>

using namespace std;


const int MAX = (1<<7) + 2;
int paper[MAX][MAX];
int ans[2];

bool check(int n, int x, int y){
    int now_val = paper[x][y];
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
        if(now_val != paper[x+i][y+j]) return false;
    }
    return true;
}

void func(int n, int x, int y){
    if(check(n, x, y)){
        ans[paper[x][y]]++;
    }
    else{
        int ns = n/2;
        for(int i=0; i<2; i++)
        for(int j=0; j<2; j++){
            func(ns, x+i*ns, y+j*ns);
        }
    }
}


int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i< N; i++)
    for(int j=0; j<N; j++) cin >> paper[i][j];
    func(N, 0, 0);
    cout << ans[0] << "\n" << ans[1];

}