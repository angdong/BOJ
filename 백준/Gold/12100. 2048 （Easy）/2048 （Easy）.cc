#include<iostream>

using namespace std;

int N;
int board[20][20];
int arr[20][20];
bool merge_already[20][20];
int cnt;
int where[5];

void move(int dir){
    // 0: 아래
    // 1: 오
    // 2: 위
    // 3: 왼
    int next_x[4] = {1, 0, -1, 0};
    int next_y[4] = {0, 1, 0, -1};
    int dx = next_x[dir];
    int dy = next_y[dir];

    for(int i=0; i<N; i++)
        fill(merge_already[i], merge_already[i]+N, false);

    if(dx){
        // up or down
        for(int i=0; i<N; i++){
            // i indicates <->
            for(int k=0; k<N; k++){
                int j;
                if(dx <0) j=k;
                else j=N-1-k;
                // j indicates start position!
                int idx=0;
                while(j+dx*(idx+1) >= 0 && j+dx*(idx+1) < N){
                    if(arr[j+dx*(idx)][i]==0){
                        break;
                    }
                    if(arr[j+dx*(idx+1)][i] > 0 && arr[j+dx*(idx+1)][i] != arr[j+dx*idx][i]){
                        break;
                    }
                    else if(arr[j+dx*(idx+1)][i]==0){
                        arr[j+dx*(idx+1)][i] = arr[j+dx*idx][i];
                    }
                    else if(arr[j+dx*(idx)][i]==arr[j+dx*(idx+1)][i]){
                        if(merge_already[j+dx*(idx+1)][i]){
                            break;
                        }
                        else{
                            arr[j+dx*(idx+1)][i] *= 2;
                            merge_already[j+dx*(idx+1)][i] = true;
                            arr[j+dx*(idx)][i] = 0;
                            break;
                        }
                    }
                    arr[j+dx*(idx)][i] = 0;
                    idx++;
                }
            }
        }
    }
    else{
        // left or right
        for(int i=0; i<N; i++){
            // i indicates <->
            for(int k=0; k<N; k++){
                
                int j=0;
                if(dy <0) j=k;
                else j=N-1-k;
                // j indicates start position!
                int idx=0;
                while(j+dy*(idx+1) >= 0 && j+dy*(idx+1) < N){
                    if(arr[i][j+dy*(idx)]==0) break;
                    if(arr[i][j+dy*(idx+1)] > 0 && arr[i][j+dy*(idx+1)] != arr[i][j+dy*idx]){
                        break;
                    }
                    else if(arr[i][j+dy*(idx+1)]==0) arr[i][j+dy*(idx+1)] = arr[i][j+dy*idx];
                    else if(arr[i][j+dy*(idx)]==arr[i][j+dy*(idx+1)]){
                        // cout << dy << " J: " << j <<" pos [" << i << ", " << j+dy*(idx+1) << "]";
                        if(merge_already[i][j+dy*(idx+1)]){
                            // cout << " Can't merge!\n";
                            break;
                        }
                        else{
                            arr[i][j+dy*(idx+1)] *= 2;
                            // cout << "merged: <" << arr[i][j+dy*(idx+1)] <<">" << "\n";
                            merge_already[i][j+dy*(idx+1)] = true;
                            arr[i][j+dy*(idx)] = 0;
                            break;        
                        }
                    }
                    arr[i][j+dy*(idx)] = 0;
                    idx++;
                }
            }
        }
    }
}

void func(int n){
    if(n==5){
        // cout << "=================\n";
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = board[i][j];
            }
        }
        // for(int j=0; j<N; j++){
        //     for(int k=0; k<N; k++){
        //         cout << arr[j][k] << " ";
        //     }
        //     cout << "\n";
        // }
        for(int i: where){
            move(i);
            // cout << "[Move] ";
            // if(i==0){
            //     cout << "⬇\n";
            // }
            // else if(i==1){
            //     cout << "➡\n";
            // }
            // else if(i==2){
            //     cout << "⬆\n";
            // }
            // else if(i==3){
            //     cout << "⬅\n";
            // }
            // for(int j=0; j<N; j++){
            //     for(int k=0; k<N; k++){
            //         cout << arr[j][k] << " ";
            //     }
            //     cout << "\n";
            // }
        }
        int tmp_max=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j] > tmp_max) tmp_max=arr[i][j];
            }
        }
        cnt = max(cnt, tmp_max);
        return;
    }
    for(int i=0; i<4; i++){
        where[n] = i;
        func(n+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
        cin >> board[i][j];
    func(0);
    cout << cnt;
}