/*
#problem
https://www.acmicpc.net/problem/2357

#review

#reference

*/
#include <iostream>

#define MAX_VAL = 1'000'000'000

using namespace std;


typedef long long int lli;
struct Node{
    lli max;
    lli min;
    void setLeaf(lli N) { max = min = N;}
};


Node seg_tree[200000];

int main(){

    int N,M;
    cin >> N >> M;

    lli input;
    for(int i=N;i<2*N;i++){
        scanf("%lld",&input);
        seg_tree[i].setLeaf(input);
    }
    for(int i=0;i<M;i++){
        int S,E;
        scanf("%d %d",&S,&E);
        S = N+S-1;
        E = N+E-1;

        Node& start = seg_tree[N+S-1];
        Node& end = seg_tree[N+E-1];
        int L = S + S%2;
        int R = E - (E+1)%2;
        
        while( L < R && L*R >0){
            L = L/2;
            R = R/2;
            for(int j=L;j<=R;j++){
                seg_tree[j].min = min(seg_tree[j*2].min,seg_tree[j*2+1].min);
                seg_tree[j].max = max(seg_tree[j*2].max,seg_tree[j*2+1].max);
            }
        }
        if(L==0) L++;
        lli min_v = min(start.min,end.min);
        lli max_v = max(start.max,end.max);
        
        min_v = min(min_v,seg_tree[L].min);
        max_v = max(max_v,seg_tree[L].max);



        printf("L: %d, R: %d\n",L,R);
        cout << min_v << " " << max_v << endl;
    }


}
