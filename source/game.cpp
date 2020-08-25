/*
# problem
https://www.acmicpc.net/problem/1103

#review

#reference
https://bit.ly/31lWhUf
*/

/*
# Dynamic Programming 의 핵심! 
    재귀 과정을 거칠 때, 이미 호출된 함수는 값을 따로 저장해두어 시간을 줄인다.
*/
#include <iostream>
#include <vector>
using namespace std;

struct Block{
    int val;
    bool isVisited;
    int res;
    Block(){ val=0; isVisited=false; res=-1;}
};

Block board[50][50];

int solve(int i=0,int j=0){
    int val;
    if(i < 0 || j < 0 || i >= 50 || j >= 50 || (val = board[i][j].val) == 0) return 0;
    
    if( board[i][j].isVisited ){
        cout << -1 << endl;
        exit(0);
    }
    if(board[i][j].res != -1) return board[i][j].res;

    board[i][j].isVisited = true;
    
    // cout << "(" << i <<"," << j <<"),"<<val<<" -> ";
    
    int &max_v= board[i][j].res =0;
    max_v = max(max_v,solve(i+val,j)+1);
    max_v = max(max_v,solve(i-val,j)+1);
    max_v = max(max_v,solve(i,j+val)+1);
    max_v = max(max_v,solve(i,j-val)+1);

    // cout << endl;
    board[i][j].isVisited = false;
    return max_v;
}


int main(){
    int N,M;
    cin >> N >> M;

    char input;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> input;
            if(input!='H')  board[i][j].val = int(input-'0');
        }
    }
    cout << solve() << endl;
}