#include<iostream>
using namespace std;
 
int arr[1000001] = { 0 };
 
int main() {
 
    int T;
    cin >> T;
 
    while (T--)
    {
        int N;
        cin >> N;
 
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
 
        long long answer = 0;
        int last = arr[N - 1];
 
        // 훗 날의 주가가 높을 때에 이익이 생긴다.
        for (int i = N-2; i >= 0; i--)
        {
            // 이익창출
            if (last > arr[i])
            {
                answer += (last - arr[i]);
            }
            // 큰 주가 갱신
            else{
                last = arr[i];
            }
        }
        if (answer <= 0) cout << 0 << '\n';
        else cout << answer << '\n';
    }
}
