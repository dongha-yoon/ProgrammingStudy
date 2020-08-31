/*
#problem
https://www.acmicpc.net/problem/1495

#review

#reference
https://mygumi.tistory.com/145

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,S,M;
    cin >> N >> S >> M;

    bool soundList[N+1][M+1];
    for(int i=0;i<N+1;i++){
        for(int j=0;j<M+1;j++)
            soundList[i][j]=false;
    }

    soundList[0][S] = true;

    for(int i=1;i<=N;i++){
        int change;
        scanf("%d",&change);
        bool flag=false;
        for(int j=0;j<=M;j++){
            
            bool &val = soundList[i-1][j];
            if(val){
                flag = true;
                if( j + change <= M ) soundList[i][j+change]=true;
                if( j - change >= 0 ) soundList[i][j-change]=true;
            }
           
        }
        if(!flag){
                cout << "-1" << endl;
                exit(0);
        }
    }
    for(int i=M;i>=0;i--){
        if(soundList[N][i]){
            cout << i << endl;
            exit(0);
        }
    }

    cout << -1 << endl;
}
