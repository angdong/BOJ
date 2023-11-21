#include<iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string cards;
    cin >> cards;
    int ans[2] = {0,};

    char now_char='m';
    for(char c: cards){
        if(c != now_char){
            now_char = c;
            ans[now_char - '0']++;
        }
    }
    int answer = ans[0] > ans[1]? ans[1]: ans[0];
    cout << answer;
}