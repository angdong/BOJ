#include<bits/stdc++.h>
using namespace std;

int V, E;
vector<pair<int, int>> way[1005];
int prev_path[1005];
int dist[1005];
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
    
    while(E--){
        int pre, nxt, dist;
        cin >> pre >> nxt >> dist;
        // {dist, nxt}
        way[pre].push_back({dist, nxt});
    }

    int st, ed;
    cin >> st >> ed;
    dist[st] = 0;
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
                prev_path[next_node.Y] = nxt;
                pq.push({dist[next_node.Y], next_node.Y});
            }
        }
    }
    cout << dist[ed] << "\n";
    deque<int> path;
    path.push_front(ed);
    int idx=ed;
    while(idx!=st){
        idx = prev_path[idx];
        path.push_front(idx);
    }
    cout << path.size() << "\n";
    while(path.size()){
        cout << path.front() << " ";
        path.pop_front();
    }
}