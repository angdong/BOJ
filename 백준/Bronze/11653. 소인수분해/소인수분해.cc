#include<iostream>

using namespace std;

int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if(N==1) return 0;
    else{
        int i=2;
        while(N>1){
            if(i*i > N){
                cout << N << "\n";
                break;
            }
            if(N % i ==0){
                N /= i;
                cout << i << "\n";
            }
            else{
                i++;
            }
        }
    }
}