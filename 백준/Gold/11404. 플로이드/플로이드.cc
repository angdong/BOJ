#include<bits/stdc++.h>
using namespace std;

int n, m;
int bus[105][105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, tmp;
        cin >> a >> b >> tmp;
        bus[a][b] = bus[a][b]==0? tmp: min(tmp, bus[a][b]);
    }
    for(int i=1; i<=n; i++){
        // i->거치는 곳
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(j==k) continue;
                if(bus[j][i] * bus[i][k] ==0) continue;
                bus[j][k] = bus[j][k]==0? bus[j][i]+bus[i][k]: min(bus[j][i]+bus[i][k], bus[j][k]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << bus[i][j] << " ";
        }
        cout << "\n";
    }
}