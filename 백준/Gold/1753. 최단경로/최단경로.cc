#include<bits/stdc++.h>
using namespace std;

int V, E;
vector<pair<int, int>> way[20005];
int dist[20005];
const int MAX = 0x3f3f3f3f;

priority_queue<pair<int, int>, vector<pair<int, int>>,
                greater<pair<int, int>>> pq;
#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    fill(dist, dist+V+1, MAX);
    int st;
    cin >> st;
    dist[st] = 0;
    while(E--){
        int pre, nxt, dist;
        cin >> pre >> nxt >> dist;
        // {dist, nxt}
        way[pre].push_back({dist, nxt});
    }

    pq.push({dist[st], st});
    while(pq.size()){
        int nxt, weight;
        tie(weight, nxt) = pq.top();
        pq.pop();

        if(dist[nxt] != weight) continue; // 이미 더 작은 값으로 초기화됨
        for(auto next_node: way[nxt]){
            // 다음 경로로 가는 길 보기
            if(dist[next_node.Y] > dist[nxt] + next_node.X){
                // 거리 새로 초기화
                dist[next_node.Y] = dist[nxt] + next_node.X;
                pq.push({dist[next_node.Y], next_node.Y});
            }
        }
    }
    for(int i=1; i<=V; i++){
        if(i==st) cout << 0;
        else if(dist[i]==MAX) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }
}