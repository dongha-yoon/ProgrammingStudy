#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;


int ans[100000];
int cor[100000];
int main(){
    
    int N,M;

    cin >> N;
    cin >> M;

    for(int i=0;i<N;i++)
        cin >> ans[i];
        
        
    for(int i=0;i<M;i++){
        int in;
        cin >> in;
        cor[i] = in-1;
    }
    
    sort(cor, cor+M);

    int cidx = 0;
    for(int i=0;i<N;i++){
        if(i == cor[cidx]){
            cidx++;
        }
        else{
            int a = ans[i];
            while( ans[i]==a || ans[i] == ans[i-1] || ans[i] == ans[i+1])
                ans[i] = (ans[i] + 1)%5 + 1;
        }
    }

    for(int i=0;i<N;i++)
        printf("%d ",ans[i]);
    printf("\n");
}