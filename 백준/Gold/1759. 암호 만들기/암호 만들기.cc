#include<iostream>
#include<algorithm>

using namespace std;

char password[16];
char arr[16];

int L, C;

void solve(int n, int st){
    if(n==L){
        int za=0;
        int mo=0;
        for(int i=0; i<L; i++){
            bool is_moum = false;
            for(char c: "aeiou"){
                if(c == password[i]){
                    is_moum = true;
                    break;
                }
            }
            if(is_moum) mo++;
            else za++;
        }
        if(mo < 1 || za < 2) return;
        for(int i=0; i<L; i++) cout << password[i];
        cout << "\n";
    }
    for(int i=st; i<C; i++){
        password[n] = arr[i];
        solve(n+1, i+1);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;

    for(int i=0; i<C; i++) cin >> arr[i];
    sort(arr, arr+C);

    solve(0, 0);
}