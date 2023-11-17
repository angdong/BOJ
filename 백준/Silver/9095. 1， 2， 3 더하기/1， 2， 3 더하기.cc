// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
// 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.
#include<iostream>

using namespace std;
int arr[100];
int T;
int n;
int main(){
    cin >> T;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4; i<11; i++){
        int tmp;
        arr[i] += arr[i-3];
        arr[i] += arr[i-2];
        arr[i] += arr[i-1];
    }
    while(T--){
        cin >> n;
        cout << arr[n] << "\n";
    }
}