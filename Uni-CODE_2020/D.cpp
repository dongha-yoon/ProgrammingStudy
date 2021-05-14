#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int R = 1000000007;

int main(){
    
    int N;
    scanf("%d",&N);
    
    long int result=0;
    long int line=0;

    int input;
    for(int i=0 ;i<N-1; i++){
        scanf("%d",&input);
        line = (line*input + input)%R;
        result = (result+line)%R;
    }

    printf("%ld",result%R);
}
