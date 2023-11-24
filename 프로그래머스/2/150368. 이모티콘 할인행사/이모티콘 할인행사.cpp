#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max_person;
int max_price;
int N;
int emo_percent[8];

void backtrack(int user_idx, vector<vector<int>> users, vector<int> emoticons){
    if(user_idx==emoticons.size()){
        // break
        int tmp_person=0;
        int tmp_price=0;
        for(int i=0; i<N; i++){
            int user_price=0;
            // emoticon에 대해서 할인 많이 되는애들 다 사기
            int user_percent = users[i][0];
            for(int j=0; j<emoticons.size(); j++){
                if(emo_percent[j] >= user_percent){
                    user_price+=emoticons[j] * (100-emo_percent[j]) / 100;
                }
            }
            if(user_price >= users[i][1]){
                // 임티플 구매
                tmp_person++;
            }
            else{
                tmp_price+=user_price;
            }
        }
        if(max_person<tmp_person){
            max_person = tmp_person;
            max_price = tmp_price;
        }
        else if(max_person==tmp_person){
            if(tmp_price > max_price) max_price=tmp_price;
        }
        
        return;
    }
    for(int percent: {10, 20, 30, 40}){
        emo_percent[user_idx] = percent;
        backtrack(user_idx+1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    // 임티플 가입자 최대한 늘리기 -> 이모티콘 판매액 늘리기
    // users: n명의 구매 기준 담은 2차원 정수 배열
    // emoticons: 임티 m개 정가를 담음 1차원 배열
    // 임티플 가입수 + 임티 매출액을 return 하기
    
    // 임티플 가입자 최대 -> 매출액 최대
    // 할인율 10/20/30/40
    N = users.size();
    vector<int> answer;
    backtrack(0, users, emoticons);
    answer.push_back(max_person);
    answer.push_back(max_price);
    return answer;
}