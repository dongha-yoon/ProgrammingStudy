/*
#problem
https://www.acmicpc.net/problem/1912

#review
https://ssyoon.tistory.com/18

#reference

*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> max_sum;

int main(){
    int N;
    cin >> N;
    
    max_sum.resize(N+1);
    int Answer=max_sum[0]=-1000;

    for(int i=1;i<N+1;i++){
        int input;
        scanf("%d",&input);
        max_sum[i] = max(max_sum[i-1]+input,input);
        Answer = max(max_sum[i],Answer);
    }
    cout << Answer << endl;
}
