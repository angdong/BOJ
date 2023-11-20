#include<iostream>
#include<algorithm>

using namespace std;

int N;
int rope[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> rope[i];
    sort(rope, rope+N);

    int max_val = rope[N-1];
    for(int i=N-2; i>=0; i--){
        if(max_val <= (N-i)* rope[i]){
            max_val = (N-i) * rope[i];
        }
    }
    cout << max_val;
}