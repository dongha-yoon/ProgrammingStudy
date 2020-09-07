/*
#problem
https://www.acmicpc.net/problem/17411
#review

#reference

*/
#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX 1'000'000'000

unordered_map<int,int> map;

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
        if(map.find(dp[i])!=map.end())  map[dp[i]]++;
        else map[dp[i]]=0;
    }
    cout << ans << " " << map[ans] << endl;
}
