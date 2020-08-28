/*
#problem
https://www.acmicpc.net/problem/11066

#review

#reference

*/
#include <iostream>
#include <algorithm>

int book[300];



using namespace std;

int main(){
    
    int T;
    cin >> T;
    for(int t_case=0; t_case<T; t_case++){
        int K;
        cin >> K;
        for(int i=0;i<K;K++)
            scanf("%d",&book[i]);

        sort(book,book+K);

        
    }
}
