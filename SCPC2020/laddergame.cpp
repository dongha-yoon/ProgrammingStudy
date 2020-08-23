/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;

struct Vertical{
    int nv; //vertical number
    vector<int> node_idx;
    Vertical(int n=0){nv=n;}
};
struct Node{
    int nv;
    int hor_idx;
    Node(int n=0,int h=0){
        nv=n;
        hor_idx=h;
    }
};
// int go(Node* it){
//     if(it->hor != NULL)
//         it = it->ver;
//     else return 0;
//     if(it->ver != NULL)
//         it = it->ver;
//     else return 0;
//     return 1;
// }

class Ladder{
    private:
        int num_j;
        vector<Vertical> v_line;
        vector<Node> NodeList;
        vector<pair<int,int>> start_dests;
    public:
        Ladder(int n=0,int k=0,int m=0);
        void setLadder();
        int go(int v, int t);
        int findBroken(int a,int b);
};
Ladder::Ladder(int n,int k,int m){
    v_line.push_back(Vertical(0));//empty line
    for(int i=1;i<=n;i++)
        v_line.push_back(Vertical(i));
    num_j = k;
    start_dests.resize(m);
}
void Ladder::setLadder(){
    int tmp1,tmp2;
    int i_count=0;
    for(int i=0;i<num_j;i++){
        scanf("%d %d",&tmp1,&tmp2);
        NodeList.push_back(Node(tmp1,i_count+1));
        NodeList.push_back(Node(tmp2,i_count));
        v_line[tmp1].node_idx.push_back(i_count++);
        v_line[tmp2].node_idx.push_back(i_count++);
    }
    for(int i=0;i<start_dests.size();i++){
        scanf("%d %d",&tmp1,&tmp2);
        start_dests[i] = make_pair(tmp1,tmp2);
    }
    // for(int i=0; i<NodeList.size();i++){
    //     cout << NodeList[i].nv << "," << NodeList[NodeList[i].hor_idx].nv << endl;
    // }
    // for(int i=1;i<v_line.size();i++){
    //     cout << "Line #" << i <<" : ";
    //     for(int j=0;j<v_line[i].node_idx.size();j++)
    //         cout << v_line[i].node_idx[j] << ", ";
    //     cout << endl;
    // }
}
int Ladder::go(int v, int t){
    
    for(int i=0;i<t;i++){
        
    }

}

int Ladder::findBroken(int a,int b){




}




int Answer;
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        
        //input.
        int N,K,M;
        scanf("%d %d %d",&N,&K,&M);
        Ladder ladder(N,K,M);
        ladder.setLadder();
        

      



		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
