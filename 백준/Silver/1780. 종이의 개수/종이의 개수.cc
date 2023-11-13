#include<iostream>
#include<cmath>

int paper[3*3*3*3*3*3*3+2][3*3*3*3*3*3*3+2];

using namespace std;

int N;
int m_paper, z_paper, p_paper;

void count_paper(int N, int row, int col){
    bool is_valid = true;
    int val = paper[row][col];
    for(int i= row; i<row+N; i++){
        for(int j=col; j<col+N; j++){
            if(paper[i][j] != val){
                is_valid=false;
                break;
            }
        }
        if(!is_valid) break;
    }
    if(is_valid){
        if(val == -1) m_paper++;
        if(val == 0) z_paper++;
        if(val == 1) p_paper++;
    }
    else{
        int nxt = N/3;
        count_paper(nxt, row, col);
        count_paper(nxt, row, col+nxt);
        count_paper(nxt, row, col+2*nxt);
        count_paper(nxt, row+nxt, col);
        count_paper(nxt, row+nxt, col+nxt);
        count_paper(nxt, row+nxt, col+2*nxt);
        count_paper(nxt, row+2*nxt, col);
        count_paper(nxt, row+2*nxt, col+nxt);
        count_paper(nxt, row+2*nxt, col+2*nxt);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> paper[i][j];
        }
    }
    count_paper(N, 0, 0);

    cout << m_paper << "\n" << z_paper << "\n" << p_paper;
}