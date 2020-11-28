#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
    
    int N;
    scanf("%d",&N);

    for(int i=0 ;i<N; i++){
        int temp;
        scanf("%d",&temp);

        if(temp%2 != (i+1)%2){
            printf("NO\n");
            exit(0);
        }
        
    }
    printf("YES\n");
}