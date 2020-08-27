/*
#problem
https://www.acmicpc.net/problem/2579

#review

#reference

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
    for(int i=1;i<=2;i++){
        sum[i] += stair[i];
        isVisited[i]=true;
    }
}

inline int getMax(int a,int b){
    return ( a>=b )? a:b;
}


int solve(int N, int& s=0){
    /*
        isVisited[N],[N-1],[N-2]
        state==0 : T T F
        state==1 : T F T
        state==2 : F T T
    */


    // cout << "N: " << N  << " - " << stair[N] << endl;

    // cout << "V: ";
    // for(int i=0;i<3;i++){
    //     cout << isVisited[N+i] << " ";
    // }
    // cout << endl << endl;

    if( N<0 || stair[N]==-1 ) return 0;
    if( sum[N] !=0 ) return sum[N];
    
    int state1, state2=0;
    int sub1 = solve(N-1,state1);
    int sub2 = solve(N-2,state2);



    if( sub1+(state1==0)? 0:stair[N] > sub2+stair[N]  )    


    return sum[N];
}



int main(){
    

    int N;
    cin >> N;
    
    int max=0;
    for(int i=1;i<=N;i++){
        scanf("%d",&stair[i]);
        // max += stair[i];
        // isVisited[i] = true;
        // if( i>2 && isVisited[i-1]==true && isVisited[i-2]==true){
        //     int pop_idx = getPopIdx(i-1,i-2);
        //     max -= stair[pop_idx];
        //     isVisited[pop_idx]=false;
        // }
    }
    init();
    
    int state;
    solve(N-1, state);


    cout << max << endl;

    for(int i=1;i<=N;i++){
            cout << isVisited[i] << " ";
    }
        
  
    // show();
}
