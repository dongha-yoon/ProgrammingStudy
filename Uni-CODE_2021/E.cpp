#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


#define SIZE 1000000
int tree[SIZE];

void dfs(int *tree, int idx, unsigned long long* step, unsigned long long target){
    (*step)++;
    // printf("step%d: %d\n",*step,tree[idx]);

    if(*step == target){
        cout << tree[idx] << endl;
        exit(0);
    }
    int left = idx*2;
    int right = left+1;

    if(tree[left] != 0){
        dfs(tree,left,step,target);
        dfs(tree,left,step,target);
    }
    if(tree[right] != 0){
        dfs(tree,right,step,target);
    }

}

int main(){
    unsigned long long N,K;
    cin >> N >> K;
    
    // for(int i=0; i<SIZE;i++)
    //     tree[i] = 0;
    
    int idx = 1;
    tree[idx++] = 1;
    for(int i=0;i<N;i++){
        int l,r;
        cin >> l >> r;
        tree[idx++] = l;
        tree[idx++] = r;
    }
    unsigned long long step = 0;
    dfs(tree,1,&step,K);
    // cout << tree[N] << endl;
}