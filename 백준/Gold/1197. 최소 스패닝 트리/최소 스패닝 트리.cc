#include<bits/stdc++.h>
using namespace std;

int V, E;
int A, B, C;
priority_queue<tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>> pq;
vector<pair<int, int>> node[10005];
vector<bool> vis(10005, false);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for(int i=0; i<E; i++){
        cin >> A >> B>> C;
        node[A].push_back({C, B}); // <가중치, 다음 노드>
        node[B].push_back({C, A});
    }
    // pq
    // <비용, 현재노드, 다음 노드>
    for(auto v: node[1]){
        pq.push({v.first, 1, v.second});
    }
    vis[1] = true;
    int num_edge=0;
    int res=0;
    while(num_edge<V-1){
        int nxt, prev, dist;
        tie(dist, prev, nxt) = pq.top();
        pq.pop();
        if(vis[nxt]) continue;
        num_edge++;
        res+= dist;
        vis[nxt] = true;
        for(auto v: node[nxt]){
            pq.push({v.first, nxt, v.second});
        }
    }
    cout << res;
}