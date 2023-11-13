#include<iostream>

using namespace std;

int N;

void func(int n, int col_1, int col_2){
    if(n==1){
        cout << col_1 << " " << col_2 << "\n";
        return;
    }
    func(n-1, col_1, 6-col_1-col_2);
    cout << col_1 << " " <<  col_2 << "\n";
    func(n-1, 6-col_1-col_2, col_2);
    // n-1개 + 1개 + n-1개 움직이기
    // n-1개 -> n-2개 + 1개 + n-2개 움직이기 ...
    // --> n + 2(n-1) + 2^2(n-2) + ....
    // 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << (1<<(N))-1 << "\n";
    func(N, 1, 3);
}