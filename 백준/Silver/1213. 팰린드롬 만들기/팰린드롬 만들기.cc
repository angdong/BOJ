#include<bits/stdc++.h>

using namespace std;

string text;
int arr[40];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> text;
    for(char c: text){
        arr[c-'A']++;
    }
    if(text.size() == 1){
        cout << text;
        return 0;
    }
    int isalready = false;
    int mid_idx = -1;
    for(int i=25; i>=0; i--){
        if(arr[i] %2 !=0 && isalready){
            cout << "I'm Sorry Hansoo";
            return 0;
        }
        if(arr[i] % 2 !=0){
            isalready=true;
            mid_idx=i;
        }
    }
    string res;

    for(int i=0; i<26; i++){
        int halfofchar = arr[i]/2;
        for(int j=0; j<halfofchar; j++){
            res+= i+'A';
            arr[i]--;
        }
    }
    if(mid_idx!=-1){
        res+= mid_idx + 'A';
        arr[mid_idx]--;
    }
    
    for(int i=25; i>=0; i--){
        for(int j=0; j<arr[i]; j++){
            res+= i+'A';
        }
    }
    cout << res;
}