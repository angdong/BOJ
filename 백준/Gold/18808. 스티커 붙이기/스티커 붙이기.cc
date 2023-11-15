#include<iostream>

using namespace std;

int N, M, K;
int notebook[40][40];
int sticker[40][40];
int sticker_width;
int cnt;

int R, C;

void rotate(){
    int tmp[40][40];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            tmp[j][R-i-1] = sticker[i][j];
        }
    }
    for(int i=0; i<C; i++){
        for(int j=0; j<R; j++){
            sticker[i][j] = tmp[i][j];
        }
    }
    int change_val = R;
    R = C;
    C = change_val;
}

bool can_sticker(int x, int y){
    if(x+R-1 > N-1) return false;
    if(y+C-1 > M-1) return false;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if (sticker[i][j]==1 && notebook[x+i][y+j]==1){
                return false;
            }
        }
    }
    return true;
}

void put_sticker(int x, int y){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(sticker[i][j]) notebook[x+i][y+j] = sticker[i][j];
        }
    }
}

void func(){
    // use N/M and R/C
    for(int t=0; t<4; t++){
        // rotate
        if(t>0){
            rotate();
        }
        for(int i=0; i<N-R+1; i++){
            for(int j=0; j<M-C+1; j++){
                if(can_sticker(i, j)){
                    cnt += sticker_width;
                    put_sticker(i, j);
                    return;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    while(K--){
        cin >> R >> C;
        sticker_width=0;
        for(int i=0; i< R; i++){
            for(int j=0; j<C; j++){
                cin >> sticker[i][j];
                if(sticker[i][j]) sticker_width++;
            }
        }
        // find if i can get a sticker
        func();
    }
    cout << cnt;
}