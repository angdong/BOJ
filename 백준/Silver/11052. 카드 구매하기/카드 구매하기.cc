#include<iostream>

using namespace std;

int N;
int cost[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> cost[i];
    
    for(int i=2; i<=N; i++){
        // N개 사야함~~ i개 사는 경우 -> max(i, (i-1) + (1), (i-2) + (2), ...)
        cost[i] = max(cost[i-1] + cost[1], cost[i]);
        int max_cost=cost[i];
        for(int j=i-1; j>0; j--){
            if(cost[j] + cost[i-j] > max_cost) max_cost = cost[j] + cost[i-j];
        }
        cost[i] = max_cost;
    }
    cout << cost[N];
}