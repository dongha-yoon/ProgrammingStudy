/*
#problem
https://www.acmicpc.net/problem/2357

#review

#reference

*/
#include <iostream>
#include <cmath>
#include <vector>

#define MAX_VAL 1'000'000'000

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
        vector<Node> tree;
        vector<int> idx;
        int height;
        int size;
    public:
        SegmentTree(vector<lli>& vec);
        void init(vector<lli>& vec, int node, int start, int end);
        int getSize() {return tree.size();}
        Node getInverval(int S,int E); 
        void printTree();
};

SegmentTree::SegmentTree(vector<lli>& vec){
    size = vec.size()-1;
    idx.resize(size+1);
    height = (int)log2(size)+1;
    tree.resize(pow(2,(height+1)));
    init(vec,1,1,size);
}

void SegmentTree::init(vector<lli>& vec, int node, int start, int end){
    if(start==end){
        idx[start] = node;
        return tree[node].setLeaf(vec[start]);
    }

    int mid = (start + end)/2;
    init(vec,node*2,start,mid);
    init(vec,node*2+1,mid+1,end);
}

Node SegmentTree::getInverval(int node, int S, int E, int L, int R){
    

    if(L>E || R<S || L<S || R>E)
        return Node();
    if(L==S || R==E)
        return tree[idx]
        
    
    return Node(max_v,min_v);
}

void SegmentTree::printTree(){
    int p=1;
    for(int i=1;i<tree.size();i++){
        if(i==(int)pow(2,p)){
            cout << endl;
            p++;
        }
        printf("(%lld,%lld) ",tree[i].max,tree[i].min);
    }

}


int main(){

    int N,M;
    cin >> N >> M;

    vector<lli> numset;
    numset.resize(N+1);

    for(int i=1;i<=N;i++)
        scanf("%lld",&numset[i]);
    
    SegmentTree segTree(numset); //set leaf.
    
    for(int i=0;i<M;i++){
        int S,E;
        scanf("%d %d",&S,&E);
        Node Ans = segTree.getInverval(1,S,E,S,E);
        
        // segTree.printTree();
    
        cout << Ans.min << " " << Ans.max << endl;
    }


}
