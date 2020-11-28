#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;

typedef pair<int,int> pii;


int main(){
    
    int N,K;
    scanf("%d %d",&N,&K);

    vector<pii> color;

    int input;
    int max=0;
    for(int i=0 ;i<K; i++){
        scanf("%d",&input);
        color.push_back(make_pair(input,i+1));    
        if(input>max)
            max=input;
    }
    if(max>(N+1)/2){
        printf("-1");
        exit(0);
    }
        
    sort(color.begin(),color.end());
    for(int i=0;i<color.size();i++)
         cout << color[i].first;

    int count=0;
    int prev;
    string output;
    while(count<N){
        for(int i=0;i<K;i++){
            if(color[i].first>0){
                if(prev==color[i].second){
                    continue;
                }
                output+=to_string(color[i].second)+" ";
                
                prev=color[i].second;
                color[i].first--;
                count++;
                break;
            }
        }
    }
    cout << output;
}