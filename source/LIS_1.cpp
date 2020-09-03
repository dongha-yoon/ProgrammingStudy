/*
#problem
https://www.acmicpc.net/problem/11053

#review

#reference
https://www.codeground.org/common/popCodegroundNote - only members are accessible.
*/
#include <iostream>

#define MAX 10000

using namespace std;

int seq[1001];
int dp[1001];

int main(){
    seq[0] = MAX;

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        scanf("%d",&seq[i]);
    }
        
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            if(seq[i] > seq[j] && dp[i] < dp[j])    dp[i] = dp[j];
        }
        dp[i]++;
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        if( dp[i] > ans) ans = dp[i];
    }
    cout << ans << endl;
}
