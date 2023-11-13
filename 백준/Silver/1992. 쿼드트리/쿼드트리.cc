#include<iostream>
#include<string>

using namespace std;

int N;
int picture[66][66];

bool check(int n, int row, int col){
    int now_val = picture[row][col];
    for(int i=row; i<row+n; i++)
    for(int j=col; j<col+n; j++){
        if(now_val != picture[i][j]){
            return false;
        }
    }
    return true;
}

void solve(int n, int row, int col){
    if(check(n, row, col)) cout << picture[row][col];
    else{
        cout << "(";
        for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            solve(n/2, row+i*(n/2), col+j*(n/2));
        cout << ")";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        string input_picture;
        cin >> input_picture;
        for(int j=0; j<N; j++) picture[i][j] = input_picture[j] - '0';
    }
    solve(N, 0, 0);
}