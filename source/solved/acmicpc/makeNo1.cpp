/*
#problem
https://www.acmicpc.net/problem/1463

#review

#reference

*/
#include <iostream>
#include <map>

using namespace std;

#define MAX_CALC_COUNT 1'000'000


map<int,int> calcount;

void init(){
    calcount[1] = 0;
    calcount[2] = calcount[3] = 1;
}

int getdivisor(int n){
    if(n%3==0 && n%2==0) return 6;
    else if(n%3==0) return 3;
    else if(n%2==0) return 2;
    return -1;
}
int getMin(int a,int b,int c=MAX_CALC_COUNT){
    int min=c;
    if(min > a) min = a;
    if(min > b) min = b;
    return min;
}

  
int solve(int n){
    if(n<1) return 0;
    else if(n<=3) return calcount[n];
    if(calcount.find(n)!=calcount.end()) return calcount[n];
    
    int div = getdivisor(n);

    if(div==6)
        calcount[n] = getMin(solve(n/3),solve(n/2))+1;
    else if(div==3)
        calcount[n] = getMin(solve(n/3),solve(n-1))+1;
    else if(div==2)
        calcount[n] = getMin(solve(n/2),solve(n-1))+1;
    else
        calcount[n] = solve(n-1)+1;

    return calcount[n];
}

int main(){
    init();
    
    int N;
    cin >> N;
    
    // solve(N);
    cout << solve(N) << endl;
    // for(auto i=calcount.begin();i!=calcount.end();i++)
    //     cout << (*i).first << " : " << (*i).second << endl;
}
