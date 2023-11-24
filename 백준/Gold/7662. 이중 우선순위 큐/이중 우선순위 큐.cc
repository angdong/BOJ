#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, k;
    cin >> T;
    while(T--){
        cin >> k;
        multiset<int> ms;
        while(k--){
            char op;
            int numb;
            cin >> op >> numb;
            if(op == 'I'){
                // insert
                ms.insert(numb);
            }
            else{
                // delete
                if(!ms.size()) continue;
                if(numb==1){
                    // max val delete
                    auto it = prev(ms.end());
                    ms.erase(it);
                }
                else{
                    // min val delete
                    auto it = ms.begin();
                    ms.erase(it);
                }
            }
        }
        if(!ms.size()) cout << "EMPTY";
        else cout << *prev(ms.end()) << " " << *ms.begin();
        cout << "\n";
    }
}