/*
#problem

#review

#reference

*/
#include <iostream>

using namespace std;


int stair[301];

int max_idx(int a,int b){
    int Va = stair[a];
    int Vb = stair[b];

    if(Va < Vb)
        return b;
    else
        return a;

}

int main(){
    stair[0]=0;

    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++)
        scanf("%d",&stair[i]);
    
    int last_idx = max_idx(N-1,N-2);
    int sum=stair[N] + stair[last_idx];
    while(last_idx > 0){
        last_idx = max_idx(last_idx-1,last_idx-2);
        sum += stair[last_idx];
    }


    
    cout << sum << endl;
    // show();
}
