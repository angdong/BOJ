#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[1001];
vector<bool> vis(1001, false);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;
    while(M--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int tmp=0;
    queue<int> bfs;
    for(int i=1; i<=N; i++){
        // 각 node 모두 순회
        if(vis[i]) continue;
        else{
            tmp++;
            bfs.push(i);
            vis[i] = true;
            while(bfs.size()){
                // 각 node들 모두 순회
                int nxt = bfs.front();
                bfs.pop();
                for(auto node: graph[nxt]){
                    if(vis[node]) continue;
                    bfs.push(node);
                    vis[node] = true;
                }
            }
        }
    }
    cout << tmp;
}