#include<iostream>
#include<cmath>

using namespace std;

const int MAX = 1024 * 3 + 2;
char star[MAX][MAX * 2 - 1];

void solve(int n, int x, int y){
    if(n==3){
        star[x][y] = '*';
        star[x+1][y-1] = '*';
        star[x+1][y+1] = '*';
        for(int i=0; i<5; i++){
            star[x+2][y-2+i] = '*';
        }
        return;
    }
    else{
        solve(n/2, x, y);
        solve(n/2, x+ n/2, y+ n/2);
        solve(n/2, x+ n/2, y- n/2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int star_length = 5 * pow(2, N/3-1) + pow(2, N/3-1) - 1;

    solve(N, 0, N-1);
    for(int i=0; i<N; i++){
        for(int j=0; j<N*2-1; j++){
            if(star[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }
}