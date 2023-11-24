#include<bits/stdc++.h>
using namespace std;


int N;
int root_node;
int remove_node;
int ans;
vector<int> child[51];

void dfs(int cur){
    if(child[cur].size() == 0){
        ans++;
    }
    else{
        for(auto v: child[cur]){
            if(v==remove_node){
                if(child[cur].size()==1) ans++;
            }
            else
                dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        if(tmp==-1){
            root_node=i;
            continue;
        }
        child[tmp].push_back(i);
    }
    cin >> remove_node;
    if(remove_node==root_node){
        cout << 0;
        return 0;
    }

    dfs(root_node);
    cout << ans;
}