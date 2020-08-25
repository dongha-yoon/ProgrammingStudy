/*
#problem
https://www.acmicpc.net/problem/1912

#review

#reference

*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> sumSet;
vector<int> max_sum;

int main(){
    int N;
    cin >> N;
    int pos=0;
    for(int i=0;i<N;i++){
        int input;
        scanf("%d",&input);
        if(input <= 0){
            if(pos!=0)
                sumSet.push_back(pos);
            sumSet.push_back(input);
            pos=0;
        }
        else
            pos+=input;
    }
    if(pos!=0)  sumSet.push_back(pos);
    
    max_sum.resize(sumSet.size());
    int Answer=max_sum[0]=sumSet[0];

    for(int i=1;i<sumSet.size();i++){
        max_sum[i] = max(max_sum[i-1]+sumSet[i],sumSet[i]);
        Answer = max(max_sum[i],Answer);
    }
    // cout << "Size : " << max_sum.size() << endl;
    cout << Answer << endl;
}
