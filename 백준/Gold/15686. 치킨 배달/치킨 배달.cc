#include<iostream>
#include<stack>

using namespace std;

int N, M;
int city[52][52];
int cnt = 9999999;
int house_num;
int chicken_num;
int house[102];
pair<int, int> chicken[13];
int chicken_list[13];


void solve(int n, int st){
    if(n==M){
        // calculate chicken distance
        fill(house, house+house_num, 9999999);
        for(int i=0; i<n; i++){
            int idx =-1;
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    if(city[j][k] != 1) continue;
                    idx++;
                    int dist = abs(j-chicken[chicken_list[i]].first) + abs(k-chicken[chicken_list[i]].second);
                    if(house[idx] > dist) house[idx] = dist;
                }
            }
        }
        int tmp_cnt=0;
        for(int i=0; i<house_num; i++) tmp_cnt += house[i];
        cnt = min(cnt, tmp_cnt);
        return;
    }
    for(int i=st; i<chicken_num; i++){
        chicken_list[n] = i;
        solve(n+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
        cin >> city[i][j];
        if(city[i][j] == 1){
            // house
            house_num++;
        }
        if(city[i][j] == 2){
            // chicken
            chicken[chicken_num++] = {i, j};
        }
    }
    solve(0, 0);
    cout << cnt;
}