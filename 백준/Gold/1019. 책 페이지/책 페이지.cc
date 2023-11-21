#include<iostream>

using namespace std;

string N;
int arr[12];
long long ans[10];

int get_front(int t, int len){
    int tmp=0;
    for(int i=1; i<t; i++){
        tmp = tmp*10 + arr[i];
    }
    return tmp;
}
int get_back(int t, int len){
    int tmp=0;
    for(int i=t+1; i<=len; i++){
        tmp = tmp*10 + arr[i];
    }
    return tmp;
}
int digits(int i){
    int t=1;
    while(i-1 >0){
        t*=10;
        i--;
    }
    return t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    int idx=1;
    for(char c: N){
        arr[idx++] = c-'0';
    }
    idx--;
    // [X][1][2][3][4][]...
    if(idx==1){
        for(int i=1; i<=arr[idx]; i++) ans[i]++;
    }
    else{
        for(int i=1; i<=idx; i++){
            // 각 자릿수별 연산
            int mid = arr[i];
            int front = get_front(i, idx);
            int back = get_back(i, idx);
            int f_digit = digits(i-1);
            int b_digit = digits(idx-i);

            if(i==1){
                // 첫 번째 자리
                ans[mid] += back +1;
                for(int j=1; j<mid; j++){
                    ans[j] += b_digit*10;
                }    
            }
            else if(i==idx){
                // 마지막 자리
                for(int j=0; j<=mid; j++){
                    // 10의 자리수 있는 경우만 해당
                    ans[j] += front+1;
                }
                ans[0]--;
                for(int j=mid+1; j<10; j++){
                    ans[j] += front;
                }
            }
            else{
                // 그 외
                // 0
                if(mid==0){
                    // 0
                    ans[0] += back+1 + (front-1) * b_digit * 10;
                }
                else{
                    // N
                    ans[mid] += back+1 + front* b_digit*10;
                    // 0
                    ans[0] += front * b_digit*10;
                }
                // 1~N-1
                for(int j=1; j<mid; j++){
                    ans[j] += (front+1) * b_digit * 10;
                }
                // N+1~9
                for(int j=mid+1; j<10; j++){
                    ans[j] += front * b_digit * 10;
                }
            }
        }
    }
    for(int i=0; i<10; i++) cout << ans[i] << " ";
}