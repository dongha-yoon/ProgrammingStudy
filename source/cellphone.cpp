#include <iostream>

using namespace std;

#define max_radix 26

typedef char* key;

struct Node;

struct Root{
    Node *rnode;
    int height;
};

struct Node{
    Node *child[max_radix];
    int path;
    int count;
};


Root tree_init(){
    Root root;
    root.height=0;

    root.rnode = new Node;
    root.rnode -> path=0;
    root.rnode -> count=0;

    return root;
}

void tree_insert(Root r,int index,key k){
    int buf=0;
    Node **ptr = NULL;

    for(int i=0;i<r.rnode->path;i++){
        if(input[buf]==r.rnode->key){
            buf++;
            ptr = r.rnode->child;
        }

    }
}


int main(){
    int N;
    scanf("%d",&N);
    char *dic[N];

    Root tree = radix_init();

    for(int i=0;i<N;i++)
        scanf("%c",dic[i]);
    


}
               +-----------+
               |           |
               |    " "    |
               |           |
        +------+-----------+------+
        |                         |
        |                         |
   +----v------+            +-----v-----+
   |           |            |           |
   |    g      |            |     c     |
   |           |            |           |
   +-----------+            +-----------+
        |                         |
        |                         |
   +----v------+            +-----v-----+
   |           |            |           |
   |    o      |            |     a     |
   |           |            |           |
   +-----------+            +-----------+
                                  |
                                  |
                            +-----v-----+
                            |           |
                            |     t     |
                            |           |
                            +-----------+