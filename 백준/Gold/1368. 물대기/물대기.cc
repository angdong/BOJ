#include<bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> node[305];
vector<bool> chk(305, 0);
priority_queue<tuple<int, int, int>,
                vector<tuple<int,int,int>>,
                greater<tuple<int,int,int>>> pq;
int res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        // pq -> {cost, prev, nxt}
        pq.push({tmp, i, i});
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int tmp;
            cin >> tmp;
            if(j>=i) continue;
            node[i].push_back({tmp, j});
            node[j].push_back({tmp, i});
        }
    }
    // 먼저 물 뚫어야 함
    int first_water, tmp, cost;
    tie(cost, first_water, tmp) = pq.top();
    chk[first_water] = 1;
    pq.pop();
    res+= cost;
    for(auto v: node[first_water]){
        pq.push({v.first, first_water, v.second});
    }

    int answer = N-1;
    while(answer > 0){
        int cost, prev, nxt;
        tie(cost, prev, nxt) = pq.top();
        pq.pop();
        if(chk[nxt]) continue;
        answer--;
        res+= cost;
        chk[nxt] = true;
        for(auto v: node[nxt]){
            pq.push({v.first, nxt, v.second});
        }
    }
    cout << res;
}