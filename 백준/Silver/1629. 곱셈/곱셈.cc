#include<iostream>

using namespace std;
#define ll long long

ll func(int a, int b, int c){
    if(b == 1) return a % c;
    ll modulo = func(a, b/2, c);
    modulo = modulo * modulo % c;
    if(b%2==0) return modulo;
    return modulo * a % c;
}

ll A, B, C;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    cout << func(A, B, C);

}