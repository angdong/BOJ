// 구간 합 구하기 5
#include<iostream>

using namespace std;

int N;
int M;
int x1, x2, y1, y2;
int arr[1030][1030];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++)
        cin >> arr[i][j];
    for(int i=1; i<=N; i++){
        for(int j=2; j<=N; j++){
            arr[i][j] += arr[i][j-1];
        }
    }

    while(M--){
        cin >> x1 >> y1 >> x2 >> y2;
        int tmp=0;
        for(int i=x1; i<=x2; i++){
            tmp += arr[i][y2];
            if(y1 != 1) tmp -= arr[i][y1-1];
        }
        cout << tmp << "\n";
    }
}