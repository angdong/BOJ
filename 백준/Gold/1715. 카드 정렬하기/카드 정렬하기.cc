#include<bits/stdc++.h>

using namespace std;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N;
    while(N--){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    int res=0;
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        res += a+b;
        pq.push(a+b);
    }
    cout << res;
}