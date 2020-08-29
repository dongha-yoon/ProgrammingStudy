/*
#problem
https://www.acmicpc.net/problem/11066

#review

#reference
http://melonicedlatte.com/algorithm/2018/03/22/051337.html

#memo
What is Kruth's optimization??
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define MAX 1'000'000'000
#define SIZE 500


int book[SIZE];
int value[SIZE][SIZE];//[start][end]
int cost[SIZE][SIZE]; 

void init(){
    for(int i=0;i<SIZE;i++){
        book[i] = MAX;
        for(int j=0;j<SIZE;j++)
            cost[i][j] = value[i][j] = 0;
    }
        
}

int getVal(int S,int T){
    if(value[S][T]!=0) return value[S][T];
    
    int sum = 0;
    for(int i=S;i<=T;i++) sum += book[i];
    return sum;
}

int solve(int S,int T){
    
    if(cost[S][T]!=0) return cost[S][T];
    if((T-S)==1) return cost[S][T] = value[S][T] = book[S] + book[T];
    else if(S==T) return cost[S][T] = 0;

    int minimum = MAX;
    int idx;
    for(int i=1;i<=T-S;i++){
        int v = solve(S,T-i) + solve(T-i+1,T);
        if( minimum > v ){
            minimum = v;
            idx = i;
        } 
    }
    cost[S][T] = cost[S][T-idx] + cost[T-idx+1][T] + getVal(S,T);
    return cost[S][T];

}


int main(){
    int T;
    cin >> T;
    for(int t_case=0; t_case<T; t_case++){
        init();

        int K;
        cin >> K;
        for(int i=0;i<K;i++)
            scanf("%d",&book[i]);
        
        // sort(book, book+K);
        solve(0,K-1);
        cout << cost[0][K-1] << endl;
        
        // cout << setw(6) << " ";
        // for(int i=0;i<K;i++) cout << setw(6) << book[i];

        // cout << endl;
        // for(int i=0;i<K;i++){
        //     cout << setw(6) << book[i] << "|";
        //     for(int j=0;j<K;j++)
        //         cout << setw(6) << cost[i][j];
        //     cout << endl;
        // }
    }
}
