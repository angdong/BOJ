#include<iostream>
#include<vector>

using namespace std;

int room[8][8];
int N, M;
int check[8][8];
int max_cnt;
int num_cctv;
int num_space;

vector<pair<int, pair<int, int>>> cctv[8];
#define X first
#define Y second

void up(int x, int y, int is_add){
    for(int i=x-1; i>=0; i--){
        if(room[i][y]==6) break;
        if(room[i][y] > 0) continue;
        check[i][y] += is_add;
    }
}

void down(int x, int y, int is_add){
    for(int i=x+1; i<N; i++){
        if(room[i][y]==6) break;
        if(room[i][y] > 0) continue;
        check[i][y] += is_add;
    }
}

void left(int x, int y, int is_add){
    for(int i=y-1; i>=0; i--){
        if(room[x][i]==6) break;
        if(room[x][i] > 0) continue;
        check[x][i] += is_add;
    }
}

void right(int x, int y, int is_add){
    for(int i=y+1; i<M; i++){
        if(room[x][i]==6) break;
        if(room[x][i] > 0) continue;
        check[x][i] += is_add;
    }
}

void cctv1(int x, int y, int direction, int is_add){
    int dx=0;
    int dy=0;
    if(direction==0){
        up(x, y, is_add);
    }
    else if(direction==1){
        right(x, y, is_add);
    }
    else if(direction==2){
        down(x, y, is_add);
    }
    else if(direction==3){
        left(x, y, is_add);
    }
}

void cctv2(int x, int y, int direction, int is_add){
    // direction 0 -> 상하, direction 1 -> 좌우
    if(direction == 0){
        up(x, y, is_add);
        down(x, y, is_add);
    }
    else{
        left(x, y, is_add);
        right(x, y, is_add);
    }
}

void cctv3(int x, int y, int direction, int is_add){
    int dx, dy;
    if(direction==0){
        up(x, y, is_add);
        right(x, y, is_add);
    }
    else if(direction==1){
        right(x, y, is_add);
        down(x, y, is_add);
    }
    else if(direction==2){
        down(x, y, is_add);
        left(x, y, is_add);
    }
    else{
        up(x, y, is_add);
        left(x, y, is_add);
    }
}

void cctv4(int x, int y, int direction, int is_add){
    if(direction == 0){
        up(x, y, is_add);
        right(x, y, is_add);
        left(x, y, is_add);
    }
    else if(direction == 1){
        up(x, y, is_add);
        right(x, y, is_add);
        down(x, y, is_add);
    }
    else if(direction == 2){
        right(x, y, is_add);
        down(x, y, is_add);
        left(x, y, is_add);
    }
    else{
        up(x, y, is_add);
        down(x, y, is_add);
        left(x, y, is_add);
    }
}

void cctv5(int x, int y, int direction, int is_add){
    up(x, y, is_add);
    right(x, y, is_add);
    down(x, y, is_add);
    left(x, y, is_add);
}

void solve(int n){
    // cout << "solve func inner: "<< n << "\n";
    if(n==num_cctv){
        int tmp_cnt=0;
        // cout << "N: " << N << ", " << "M: " << M << "\n";
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(check[i][j] >0) tmp_cnt++;
                // if(check[i][j]) cout << "#";
                // else cout << room[i][j];
                // cout << " ";
            }
            // cout << "\n";
        }
        max_cnt = max(max_cnt, tmp_cnt);
        // cout << "\n";
        // cout << "temp_count [" << tmp_cnt <<"]" <<"\n";
        return;
    }
    for(int i=0; i<cctv[n].size(); i++){
        // cout << "print i: " << i << "\n";
        // cout << cctv[n].size() << " " << cctv[n][i].X<< "\n";
        if(cctv[n][i].X == 1){
            cctv1(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%4, 1);
            solve(n+1);
            cctv1(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%4, -1);
        }
        if(cctv[n][i].X == 2){
            cctv2(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%2, 1);
            solve(n+1);
            cctv2(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%2, -1);
        }
        if(cctv[n][i].X == 3){
            cctv3(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%4, 1);
            solve(n+1);
            cctv3(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%4, -1);
        }
        if(cctv[n][i].X == 4){
            cctv4(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%4, 1);
            solve(n+1);
            cctv4(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%4, -1);
        }
        if(cctv[n][i].X == 5){
            cctv5(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%4, 1);
            solve(n+1);
            cctv5(cctv[n][i].Y.X, cctv[n][i].Y.Y, i%4, -1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> room[i][j];
            if(room[i][j]==0) num_space++;
            if(room[i][j] > 0 && room[i][j] < 6){
                // vector<pair<int, int>> cctv[8];
                if(room[i][j] == 1 || room[i][j] == 3 || room[i][j] == 4){
                    cctv[num_cctv].push_back({room[i][j], {i, j}});
                    cctv[num_cctv].push_back({room[i][j], {i, j}});
                    cctv[num_cctv].push_back({room[i][j], {i, j}});
                    cctv[num_cctv].push_back({room[i][j], {i, j}});
                }
                if(room[i][j] == 2){
                    cctv[num_cctv].push_back({room[i][j], {i, j}});
                    cctv[num_cctv].push_back({room[i][j], {i, j}});
                }
                if(room[i][j] == 5){
                    cctv[num_cctv].push_back({room[i][j], {i, j}});
                }
                num_cctv++;
            }
        }
    }
    solve(0);
    cout << num_space - max_cnt;
}