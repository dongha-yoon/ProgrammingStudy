/*
#problem
https://www.acmicpc.net/problem/2357

#review

#reference

*/
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

#define MAX_VAL 1'000'000'000

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> Node;


class SegmentTree{
    private:
        Node* tree;
        int height;
        int size;
    public:
        SegmentTree(vector<lli>& vec);
        Node init(vector<lli>& vec, int node, int start, int end);
        Node getInverval(int node, int S, int E, int L, int R);
        void printTree();
        ~SegmentTree(){ delete [] tree;}
};

SegmentTree::SegmentTree(vector<lli>& vec){
    size = vec.size()-1;
    height = (int)log2(size)+1;
    tree = new Node[(int)pow(2,(height+1))];
    init(vec,1,1,size);
}

Node SegmentTree::init(vector<lli>& vec, int node, int start, int end){
    if(start==end)
        tree[node].first = tree[node].second = vec[start];
    else{
        int mid = (start + end)/2;
        Node left = init(vec,node*2,start,mid);
        Node right = init(vec,node*2+1,mid+1,end);

        tree[node].first = max(left.first,right.first);
        tree[node].second = min(left.second,right.second);
    }
    return tree[node];

}

Node SegmentTree::getInverval(int node, int S, int E, int L, int R){
    // printf("node: %d, S: %d, E: %d\n",node,S,E);
    if(S>=L && E<=R)
        return tree[node];
    else if(R<S || L>E)
        return make_pair(0,MAX_VAL);

    int mid = (S+E)/2;
    Node left = getInverval(node*2,S,mid,L,R);
    Node right = getInverval(node*2+1,mid+1,E,L,R);
    Node res;
    res.first = max(left.first,right.first);
    res.second = min(left.second,right.second);
    return res;
}

void SegmentTree::printTree(){
    int p=1;
    for(int i=1;i<size;i++){
        if(i==(int)pow(2,p)){
            cout << endl;
            p++;
        }
        printf("(%lld,%lld) ",tree[i].second,tree[i].first);
    }
    printf("\n");
}


int main(){

    int N,M;
    cin >> N >> M;

    vector<lli> numset;
    numset.resize(N+1);

    for(int i=1;i<=N;i++)
        scanf("%lld",&numset[i]);
    
    SegmentTree segTree(numset); //set leaf.
    
    int L,R;
    Node Ans;
    while(M--){
        
        scanf("%d %d",&L,&R);
        // cout <<"@#@@@#" << L << " " << R << endl;
        Ans = segTree.getInverval(1,1,N,L,R);
        
        // segTree.printTree();
    
        cout << Ans.second << " " << Ans.first << endl;
    }


}
