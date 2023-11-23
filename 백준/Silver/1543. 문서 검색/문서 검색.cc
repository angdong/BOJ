#include<bits/stdc++.h>

using namespace std;

string document;
string find_word;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, document);
    getline(cin, find_word);
    int pos=0;
    int res=0;
    while(document.find(find_word, pos) != -1){
        res++;
        pos=document.find(find_word, pos) + find_word.size();
    }
    cout << res;
}