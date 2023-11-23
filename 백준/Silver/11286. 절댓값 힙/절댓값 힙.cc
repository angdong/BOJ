#include<bits/stdc++.h>

using namespace std;


int N;
int x;

class cmp{
public:
    bool operator()(int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        else return a>0 && b <0;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, cmp> pq;

    cin >> N;
    while(N--){
        cin >> x;
        if(x!=0){
            pq.push(x);
        }
        else{
            if(pq.size()==0){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}