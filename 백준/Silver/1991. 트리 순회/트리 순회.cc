#include<bits/stdc++.h>
using namespace std;

int N;
int l[28];
int r[28];

void pre_search(int cur){
    cout << char('A' + cur-1);
    if(l[cur]) pre_search(l[cur]);
    if(r[cur]) pre_search(r[cur]);
}

void center_search(int cur){
    if(l[cur]) center_search(l[cur]);
    cout << char('A' + cur-1);
    if(r[cur]) center_search(r[cur]);
}

void post_search(int cur){
    if(l[cur]) post_search(l[cur]);
    if(r[cur]) post_search(r[cur]);
    cout << char('A' + cur-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        char p, l_node, r_node;
        cin >> p >> l_node >> r_node;
        if(l_node!='.') l[p-'A'+1] = l_node-'A' +1;
        if(r_node!='.') r[p-'A'+1] = r_node-'A' +1;
    }
    pre_search(1); cout<<"\n";
    center_search(1); cout<<"\n";
    post_search(1); cout<<"\n";
}