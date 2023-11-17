#include<iostream>

using namespace std;

int house[1000][3];
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> house[i][j];
        }
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            // 0 -> 1, 2
            // 1 -> 0, 2
            // 2 -> 0, 1
            int tmp[2];
            int idx = 0;
            for(int k=0; k<3; k++){
                if(k==j) continue;
                tmp[idx++] = k;
            }
            house[i][j] = min(house[i-1][tmp[0]], house[i-1][tmp[1]]) + house[i][j];
        }
    }
    int min_val = house[N-1][0];
    for(int i=1; i<3; i++){
        if(house[N-1][i] < min_val) min_val = house[N-1][i];
    }
    cout << min_val;
}