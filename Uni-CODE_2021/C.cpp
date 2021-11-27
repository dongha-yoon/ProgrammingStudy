#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;


char str[1000000];

int dp(char* in, int start, int end){
    if(end-start < 2)
        return 0;
    
    if(end-start == 2){
        if(in[start] == in[start+1])
            return 1;
        else
            return 0;
    }
    int mid = (start+end)/2;
    int l = dp(in,start,mid);
    int r = dp(in,mid,end);

    printf("[%d,%d,%d] l:%d, r:%d\n",start,mid,end,l,r);
    if(l+r == 0){
        if(in[mid-1] == in[mid])
            return (end-mid-1) * (mid-start-1);
        else
            return 0;
    }
    else{
        return (l+1)*(r+1);
    }
}

int main(){
    int N;
    cin >> N;
    
    scanf("%s",str);
    cout << dp(str,0,N) << endl;
}