#include<stack>
#include<iostream>
#include<vector>

using namespace std;

int N;

vector<vector<int>> G(100005);
int parent[100005];

void dfs(int cur){
    for(const int &nxt: G[cur]){
        if(parent[cur] == nxt) continue;
        parent[nxt] = cur;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1);
    for(int i=2; i<N+1; i++){
        cout << parent[i] << "\n";
    }
    return 0;
}