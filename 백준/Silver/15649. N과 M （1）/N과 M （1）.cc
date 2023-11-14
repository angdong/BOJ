#include<iostream>

using namespace std;

int arr[8];
int N, M;
bool contained_number[8];


void func(int n, int m, int arr[], int &numb){
    if(numb==m){
        for(int i=0; i<m; i++){
            cout << arr[i]+1 << " ";
        }
        cout << "\n";
    }
    else{
        for(int i=0; i<n; i++){
            if(contained_number[i]) continue;
            arr[numb++] = i;
            contained_number[i] = true;
            func(n, m, arr, numb);
            contained_number[arr[numb-1]] = false;
            numb--;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(contained_number, contained_number+8, false);

    cin >> N >> M;
    int numb = 0;
    func(N, M, arr,numb);
}