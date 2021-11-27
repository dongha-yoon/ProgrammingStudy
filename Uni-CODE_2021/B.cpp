#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;


int ans[100000];

int main(){
    unsigned long long N, ans;
    cin >> N;
    ans = N;

    unsigned long long scale = 1;
    while(true){
        int dig = (ans / scale) % 10;
        if(dig >= 5){
            ans += (10-dig)*scale;
            ans = (ans/scale)*scale;
            
        }
        //printf("dig: %d, scale: %15lld, num: %lld\n",dig, scale, ans);

        if(ans/scale == 0 && dig == 0)
            break;
        
        scale *= 10;
        
    }

    cout << ans << endl;
}