#include<bits/stdc++.h>

using namespace std;

int N, M, V;
vector<int> graph[1001];
vector<bool> vis(1001, false);

void bfs_search(){
    queue<int> bfs;
    bfs.push(V);
    vis[V] = true;
    while(bfs.size()){
        // 각 node들 모두 순회
        int nxt = bfs.front();
        cout << nxt << " ";
        bfs.pop();
        for(auto node: graph[nxt]){
            if(vis[node]) continue;
            bfs.push(node);
            vis[node] = true;
        }
    }
}

void dfs_search(int val){
    vis[val] = true;
    cout << val << " ";
    for(auto node: graph[val]){
        if(!vis[node]){
           dfs_search(node);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;
    cin >> V;
    while(M--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=N; i++) sort(graph[i].begin(), graph[i].end());

    dfs_search(V);
    cout << "\n";
    fill(vis.begin(), vis.end(), false);
    bfs_search();
}