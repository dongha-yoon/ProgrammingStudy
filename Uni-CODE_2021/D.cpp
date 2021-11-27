#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int tcase=0;tcase<T;tcase++){
        int N,K;
        cin >> N >> K;

        char num[30];
        scanf("%s", num);
        
        int dig_a = K;
        int dig_b = N-K;
        unsigned long long a=0;
        unsigned long long b=0;
        for(int i=0; i<N;i++){
            int scan = min(dig_a,dig_b) + 1;
            if(i+scan > N)
                scan = N-i;

            char max = '0';
            for(int j=0;j<scan;j++){
                if(num[i+j] > max)
                    max = num[i+j];
            }

            if(max != num[i]){
                if(dig_a > dig_b && dig_b>0)
                    b += (num[i]-48)*pow(10,--dig_b);
                else
                    a += (num[i]-48)*pow(10,--dig_a);
            }
            else{
                if(dig_a > dig_b && dig_a>0)
                    a += (num[i]-48)*pow(10,--dig_a);
                else
                    b += (num[i]-48)*pow(10,--dig_b);
            }
        }
        // printf("%lld+%lld = ",a,b);
        // cout << a+b << endl;
        printf("%lld\n",a+b);
    }
}