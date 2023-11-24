#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> jewel;
multiset<int> bag;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, M, V, C;
    // 보석을 가격/무게 순으로 정렬 후 가방에 담을 수 있는지 확인하기
    cin >> N >> K;
    for(int i=0; i<N; i++){
        // insert jewel
        cin >> M; // weight
        cin >> V; // price
        jewel.push_back({V, M});
    }
    sort(jewel.begin(), jewel.end());
    while(K--){
        cin >> C;
        bag.insert(C);
    }
    long long ans=0;
    for(int i=N-1; i>=0; i--){
        // 높은 가격의 보석부터 가방에 담을 수 있는지 확인하기
        int price, weight;
        tie(price, weight) = jewel[i];
        // 무게 해당하는 가방 있는지 확인(lower_bound)
        auto my_bag = bag.lower_bound(weight);
        if(my_bag == bag.end()) continue;
        ans += price;
        bag.erase(my_bag);
    }
    cout << ans;
}