/*
# problem
https://www.acmicpc.net/problem/3998

#review

#reference

*/
#include <iostream>
#include <vector>
#include <cmath>    
#include <map>
#include <algorithm>

#define MP 97.05276
#define MQ 128.05858

using namespace std;


char protein[400];
map<double,pair<int,int>> comb;


struct Peak{
    int numP;
    int numQ;
    Peak(int p=0, int q=0) { numP=p; numQ=q;}
};

vector<Peak> numPQ;


vector<int> pre_idx;
vector<int> suf_idx;

int solve(int np=0,int nq=0){
    
}



void init(){
    cout.precision(10);
    for(int i=0;i<=400;i++){
        protein[i] = 'X';
        for(int j=0;j<=400;j++){
            double tmp = round((MP*i + MQ*j) * 1'000'000) / 1'000'000;
            comb.insert(make_pair(tmp,make_pair(i,j)));
        }
    }
}
bool setPrior(Peak& a,Peak& b){
    if(a.numP < b.numP) return true;
    else if(a.numP == b.numP)
        return a.numQ < b.numQ;
    return false;
}

int main(){
    init();
    int N;
    scanf("%d",&N);
    
    
    double maxV=0;
    for(int i=0;i<N;i++){
        double input;
        cin >> input;
        if(comb.find(input)!= comb.end()){
            maxV = max(maxV,input);
            numPQ.push_back(Peak(comb[input].first,comb[input].second));
        }
    }
    sort(numPQ.begin(),numPQ.end(),setPrior);

}
