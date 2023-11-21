#include<iostream>

using namespace std;

int T;

int gcd(int a, int b){
    if(b==0)
        return a;
    else{
        return gcd(b, a%b);
    }
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        int x,y;
        int M,N;
        cin >> M >> N >> x >> y;
        // [2, 3]
        //  1 1/2 2/1 3/2 1/1 2/2 3
        //   1   2   3   4   5   6
        bool isvalid=false;
        for(int i=x; i<=lcm(M, N); i+=M){
            if(i % N == y || (y == N && i%N==0)){
                isvalid=true;
                cout << i << "\n";
                break;
            }
        }
        if(!isvalid) cout << -1 << "\n";
    }
}