/*
#problem
https://www.acmicpc.net/problem/10942

#review
https://ssyoon.tistory.com/19

#reference

*/
#include <iostream>
#include <map>


using namespace std;

int dp[2001][2001];
int arr[2001];

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
        printf("%d\n",dp[input2][input1]);
    }
}
