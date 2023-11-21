#include<iostream>

using namespace std;

int arr[50];
char oper[50];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 값을 최소로 만들어야 한다
    // A-B-C-D
    // A+B-C+D
    // A-B-C+D
    // A+B-C-D
    // 수와 수 사이에는 무조건 연산자 들어감, +혹은 -
    string numbs;
    cin >> numbs;
    int arr_num=0;
    int op_num=0;
    // 빼기 한 번이라도 나오면 -> 뒤에거 다 빼버리기
    for(char c: numbs){
        if(c == '+' || c == '-'){
            arr_num++;
            oper[op_num++] = c;
        }
        else{
            // numb
            arr[arr_num] = arr[arr_num] * 10 + (c - '0');
        }
    }
    int res=arr[0];
    for(int i=0; i<op_num; i++){
        bool all_minus=false;
        if(oper[i] == '-'){
            all_minus=true;
            for(int j=i+1; j<=arr_num; j++){
                res -= arr[j];
            }
        }
        else{
            res+=arr[i+1];
        }
        if(all_minus) break;
    }
    cout << res << "\n";
    // cout << arr_num << " " << op_num;
}