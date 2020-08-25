/*
# problem
https://www.acmicpc.net/problem/2839

#review

#reference

*/
#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

int sugar[5001];

void init(){
    for(int i=0;i<=5000;i++)
        sugar[i] = MAX;
    sugar[3] = sugar[5] = 1;
}

int main(){
    init();
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
            if(sugar[i]==-1)
                continue;
            else{
                sugar[i+3] = min(sugar[i+3],sugar[i] + 1);
                sugar[i+5] = min(sugar[i+5],sugar[i] + 1);
            }
        }
    cout << (sugar[N]==MAX? -1:sugar[N]) << endl;
}
