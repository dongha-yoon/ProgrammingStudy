/*
# problem
https://www.acmicpc.net/problem/3998

#review

#reference

*/
#include <iostream>
#include <iomanip>
#include <map>

#define MP 97.05276
#define MQ 128.05858

using namespace std;

map<long double,pair<int,int>> comb;

void init(){
    for(int i=0;i<=400;i++){
        for(int j=0;j<=400;j++){
            // cout << (MP*i + MQ*j) << " ";
            comb.insert(make_pair(MP*i + MQ*j,make_pair(i,j)));
        }
        // cout << endl;
    }
}




int main(){
    init();
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        double input;
        cin.precision(30);
        cin >> input;
        cout << input << endl;
        if(comb.find(input)!= comb.end())
            cout << input << " : " << comb[input].first << "," << comb[input].second << endl;

    }

}