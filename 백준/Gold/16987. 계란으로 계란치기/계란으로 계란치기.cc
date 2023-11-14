#include<iostream>

using namespace std;

int egg_candi[16];
pair<int, int> egg[8];
#define X first
#define Y second

int N;
int cnt; // ans;
int egg_damage[8];

void break_egg(int n){
    if(n==N){
        // return
        fill(egg_damage, egg_damage+8, 0);
        // for(int i=0; i<N; i++){
        //     cout << "[" << egg_candi[2*i] << ", "<< egg_candi[2*i+1] << "] ";
        // }
        // cout<< "\n";
        int tmp_eggs = 0;
        for(int i=0; i<N; i++){
            int first_egg = egg_candi[2*i];
            int second_egg = egg_candi[2*i+1];
            // 계란이 없음;
            if(egg[first_egg].X - egg_damage[first_egg] <= 0) continue;
            if(egg[second_egg].X - egg_damage[second_egg] <=0) continue;
            egg_damage[first_egg] += egg[second_egg].Y;
            egg_damage[second_egg] += egg[first_egg].Y;
            if(egg[first_egg].X - egg_damage[first_egg] <= 0) tmp_eggs++;
            if(egg[second_egg].X - egg_damage[second_egg] <= 0) tmp_eggs++;
        }
        cnt = max(cnt, tmp_eggs);
        return;
    }
    egg_candi[2*n] = n;
    for(int i=0; i<N; i++){
        if(i==n) continue;
        egg_candi[2*n+1] = i;
        break_egg(n+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int negu, muge;
        cin >> negu >> muge;
        egg[i] = {negu, muge};
    }
    break_egg(0);
    cout << cnt;
}