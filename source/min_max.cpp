/*
#problem
https://www.acmicpc.net/problem/2357

#review

#reference

*/
#include <iostream>
#include <cmath>
#include <vector>

#define MAX_VAL = 1'000'000'000

using namespace std;


typedef long long int lli;
struct Node{
    lli max;
    lli min;
    Node(int a=0, int b=MAX_VAL){ max=a; min=b;}
    void setLeaf(lli N) { max = min = N;}
};

class SegmentTree{
    private:
        Node node_arr*;
        int height;
    public:
        SegmentTree(vector<lli>& vec);
        ~SegmentTree(){delete [] node_arr;}
    
};

SegmentTree::SegmentTree(vector<lli>& vec){
    height = (int)log2(vec.size());
    node_arr = new Node[pow(2,height+1)];



}


int main(){

    int N,M;
    cin >> N >> M;

    vector<lli> numset(N);

    for(int i=0;i<N;i++)
        scanf("%lld",&numset[i]);
    
    SegmentTree segTree(numset); //set leaf.


    for(int i=0;i<M;i++){
        int S,E;
        scanf("%d %d",&S,&E);
        S = N+S-1;
        E = N+E-1;

        lli min_v = min(seg_tree[S].min,seg_tree[E].min);
        lli max_v = max(seg_tree[S].max,seg_tree[E].max);
        
        int L = S;// + S%2;
        int R = E;// - (E+1)%2;
        
        while( L < R && L*R >0){
            printf("L: %d, R: %d\n",L,R);
            if(L%2==1){
                min_v = min(min_v,seg_tree[L].min);
                max_v = max(max_v,seg_tree[L].max);
                L = L+1;
            }
            if(R%2==0){
                min_v = min(min_v,seg_tree[R].min);
                max_v = max(max_v,seg_tree[R].max);
                R = R-1;
            }

            L = L/2;
            R = R/2;
            printf("L: %d, R: %d\n",L,R);
            for(int j=L;j<=R;j++){
                int a,b;
                a = seg_tree[j].min = min(seg_tree[j*2].min,seg_tree[j*2+1].min);
                b = seg_tree[j].max = max(seg_tree[j*2].max,seg_tree[j*2+1].max);
                printf("j: %d- a: %d, b: %d\n",j,a,b);
            }
            
        }
        // if(L==0) L++;
        
        
        min_v = min(min_v,seg_tree[L].min);
        max_v = max(max_v,seg_tree[L].max);



        printf("L: %d, R: %d\n",L,R);
        cout << min_v << " " << max_v << endl;
    }


}
