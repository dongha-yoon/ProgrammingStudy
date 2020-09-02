/*
#problem
https://www.acmicpc.net/problem/10942

#review

#reference

*/
#include <iostream>
#include <map>


using namespace std;


int dp[2001][2001];
int arr[2001];

// int solve(int S,int E){
//     if(S==E) return dp[S][E]=1;
//     if(E-S == 1) return dp[S][E]=(arr[S]==arr[E])? 1:-1;
//     if(dp[S][E]!=0) return dp[S][E];
    
//     if(arr[S]==arr[E]) return dp[S][E]=solve(S+1,E-1);
//     else return dp[S][E]= -1;
// }


int main(){

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
        dp[i][i]=1;
        for(int j=i-1;j>0;j--){
            if(arr[i]==arr[j]){
                if (dp[i-1][j+1]==1 || j+2>i ) dp[i][j]=1;
            }
        }
    }

    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        int input1,input2;
        scanf("%d %d",&input1,&input2);
        // solve(input1,input2);
        // if(input1 > input2) continue;
        printf("%d\n",dp[input2][input1]);
    }

    // for(auto i=dp.begin();i!=dp.end();i++){
    //     cout << i->first.first << " -> " << i->first.second << " : " << i->second <<endl;
    // }
}
