/*
#problem
https://www.acmicpc.net/problem/10942

#review

#reference

*/
#include <iostream>
#include <map>


using namespace std;


typedef pair<int,int> pii;

map<pii,int> dp;
int arr[2001];

int solve(int S,int E){
    if(S==E) return dp[pii(S,E)]=1;
    if(E-S == 1) return dp[pii(S,E)]=(arr[S]==arr[E])? 1:0;
    if(dp.find(pii(S,E))!=dp.end()) return dp[pii(S,E)];
    
    if(arr[S]==arr[E]) return dp[pii(S,E)]=solve(S+1,E-1);
    else return dp[pii(S,E)]= 0;
}


int main(){

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
    }
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        int input1,input2;
        scanf("%d %d",&input1,&input2);
    
        cout << solve(input1,input2) << endl;
    }
}
