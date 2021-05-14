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

    for(int i=0;i<N;i++){
        scanf("%d",&seq[i]);
    }

    dp[0] = 0;
    int length = 0;
    for(int i=0;i<N;i++){
        if(dp[length] < seq[i])
            dp[++length] = seq[i];
        else{
            int s = 0;
            int e = i;
            while(s<e){
                int m = (s+e)/2;
                if(dp[m] >= seq[i])
                    e = m;
                else
                    s = m+1;
            }
            dp[e] = seq[i];
        }
    }
    for(int i=0;i<N;i++)
        cout << dp[i] << " ";
    cout << endl;
    cout << length << endl;
}
