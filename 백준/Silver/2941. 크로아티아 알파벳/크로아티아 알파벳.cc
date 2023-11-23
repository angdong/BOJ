#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string alpha_list[8] = {"c=", "c-", "dz=", "d-", "lj", "z=", "nj", "s="};
    string alpha_input;
    cin >> alpha_input;
    for(auto s: alpha_list){
        while(alpha_input.find(s)!=-1){
            int it = alpha_input.find(s);
            alpha_input.replace(it, s.size(), "#");
        }
    }
    cout << alpha_input.size();
}