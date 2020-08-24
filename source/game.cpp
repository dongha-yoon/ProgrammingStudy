/*
# problem
https://www.acmicpc.net/problem/1103

#review

*/

#include <iostream>
#include <vector>

#define INF 999'999'999

using namespace std;

struct Block{
    int val;
    bool isVisited;
    Block *next;
    Block(){ val=0; isVisited=false; next=NULL; }
};

Block board[50][50];

inline int getVal(int i,int j){
    if(i < 0 || j < 0 || i >= 50 || j >= 50)    return 0;
    else    return board[i][j].val;
}

int solve(int i=0,int j=0){
    int val = board[i][j].val;

    if(getVal(i,j)==0) return 0;
    if( board[i][j].isVisited ) return INF;

    int max_v=0
    return max_v;
}


int main(){
    int N,M;
    cin >> N >> M;

    string input;
    for(int i=0;i<N;i++){
        cin >> input;
        for(int j=0;j<M;j++){
            if(input[j]!='H') board[i][j].val = stoi(input[j]);
        }
    }
    board[0][0].isVisited = true;
    board.solve()
}