/*
#problem
https://www.acmicpc.net/problem/14501

#review

#reference

*/
#include <iostream>

using namespace std;

int cost[16];
int pay[16];
int dp[16];

int solve(int N=0){
    
    if(N > 15 || cost[N]==0 || cost[N]==-1) return 0;
    if(dp[N]!=0) return dp[N];
    
    if( (N+cost[N]) > 15) return 0;
    if(cost[N+cost[N]]==0 ) return dp[N]=solve(N+1);
    
    if(cost[N]==1) return dp[N]=pay[N]+solve(N+1);
    int maxv=pay[N]+solve(N+cost[N]);
    for(int i=1;i<cost[N];i++){
        maxv = max(maxv, solve(N+i));
    }
    return dp[N] = maxv;
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> cost[i] >> pay[i];
    cost[N] = -1;

    solve();
    // for(int i=0;i<N;i++)
    //     cout << dp[i] << " ";
    cout << dp[0] << endl;
}
