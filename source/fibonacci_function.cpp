/*
# problem
https://www.acmicpc.net/problem/1003

#review

*/

#include <iostream>

using namespace std;

pair<int,int> F_call[41];
// int fibonacci(int n) {
//     if (n == 0) {
//         printf("0");
//         return 0;
//     } else if (n == 1) {
//         printf("1");
//         return 1;
//     } else {
//         return fibonacci(n‐1) + fibonacci(n‐2);
//     }
// }

int main(){
    //initialization
    for(int i=0;i<41;i++) F_call[i].first = F_call[i].second = -1;
    F_call[0].first = 1;
    F_call[0].second = 0;
    F_call[1].first = 0;
    F_call[1].second = 1;

    int test_case;
    cin >> test_case;
    for(int i=0;i<test_case;i++){
        
        int N;
        cin >> N;

        if(F_call[N].first==-1){
            for(int i=2;i<=N;i++){
                F_call[i].first = F_call[i-1].first + F_call[i-2].first;
                F_call[i].second = F_call[i-1].second + F_call[i-2].second;
            }
        }
        cout << F_call[N].first << " " << F_call[N].second << endl;
    }
}