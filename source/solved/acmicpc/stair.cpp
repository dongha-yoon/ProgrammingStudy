/*
#problem
https://www.acmicpc.net/problem/2579

#review

#reference
https://mygumi.tistory.com/100
*/
#include <iostream>

using namespace std;

#define MAX 305

int stair[MAX];
bool isVisited[MAX];
int sum[MAX];


void init(){
    for(int i=0;i<301;i++){
        stair[i] = -1;
        isVisited[i] = false;
        sum[i] = 0;
    }
}

inline int getMax(int a,int b){
    return ( a>=b )? a:b;
}

int solve(int N){
/*
    DP[N] = MAX ( DP[N-3] + SCORE[N-1], DP[N-2] ) + SCORE[N]
*/

    if( N<0 || stair[N]==-1 ) return 0;
    if( sum[N] !=0 ) return sum[N];

    isVisited[N] = true;
    if(isVisited[N+1]==true && isVisited[N+2]==true) return -1;

    sum[N] = getMax(solve(N-3)+stair[N-1], solve(N-2)) + stair[N];

    isVisited[N] = false;
    return sum[N];
}



int main(){
    
    int N;
    cin >> N;
    
    init();

    int max=0;
    for(int i=1;i<=N;i++)
        scanf("%d",&stair[i]);
    
    cout << solve(N) << endl;
}
