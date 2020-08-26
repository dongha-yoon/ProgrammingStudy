/*
#problem
https://www.acmicpc.net/problem/9251

#review

#reference
https://www.codeground.org/common/popCodegroundNote -> DP2-LCS
*/
#include <iostream>
#include <string>
using namespace std;

#define MAX 1001

int lcs[MAX][MAX];
string a, b;

void init(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if( i==0 || j==0 ) lcs[i][j]=0;
            else lcs[i][j]=-1;
        }
    }
}

int solve(int i,int j){
    if(lcs[i][j]==0) return 0;
    if(lcs[i][j]!=-1) return lcs[i][j];

    if(a[i-1]==b[j-1]) return lcs[i][j]=solve(i-1,j-1)+1;
    else return lcs[i][j]=max(solve(i-1,j),solve(i,j-1));
}

void show(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(lcs[i][j]==-1) cout << " ";
            else cout << lcs[i][j];
        }
        cout << endl;
    }
}

int main() {
    init();
    cin >> a >> b;

    int s1=a.size();
    int s2=b.size();
    
    cout << solve(s1,s2) << endl;
    // show();
    return 0;
}