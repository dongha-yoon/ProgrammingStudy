/*
# problem
https://www.codeground.org/practice/
100	SCPC 2019 Online	
Drone exploration

#review
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;

struct Node{
    int x,y;
    Node(int a=0,int b=0){ x=a; y=b;}
};

inline int getDistance(Node n1, Node n2){
    return abs(n1.x-n2.x)+abs(n1.y-n2.y);
}

struct T_B{
    int w,h;
    T_B(int a=0,int b=0){ w=a; h=b;}
};


class Cave{
    private:
        Node start,
              end;
        vector<T_B> cel;
        vector<T_B> flo; 
        vector<vector<Node>> chk_point;
    public:
        Cave(int L,int S,int E);
        void setCel(int N);
        void setFlo(int N);
        void setNode();
        
};

Cave::Cave(int L=0,int S=0,int E=0){
    start = Node(0,S);
    end = Node(L,E);
}
void Cave::setCel(int N){
    for(int i=0;i<N;i++){
            int a,b;
            cin >> a >> b;
            cel.push_back(T_B(a,b));
        }
}
void Cave::setFlo(int N){
    for(int i=0;i<N;i++){
            int a,b;
            cin >> a >> b;
            flo.push_back(T_B(a,b));
        }
}
void Cave::setNode(){
    int c_x =0,
        f_x =0;
    chk_point.push_back(vector<Node>(1,start));

    auto c = cel.begin(),
         f = flo.begin();

    while(!(c==cel.end() && f==flo.end())){
        if( (c_x + c->w) < (f_x + f->w)){
            c_x += c->w;
            chk_point.push_back(vector<Node>(1,Node(c_x, min(c->h,(c+1)->h)) ));
            c++;
        }
        else if( (c_x + c->w) > (f_x + f->w)){
            f_x += f->w;
            chk_point.push_back(vector<Node>(1,Node(f_x, max(f->h,(f+1)->h)) ));
            f++;
        }
        else{ //if equal
            c_x += c->w;
            f_x += f->w;
            vector<Node> tmp;
            tmp.push_back(Node(c_x, min(c->h,(c+1)->h)) );
            tmp.push_back(Node(f_x, max(f->h,(f+1)->h)) );

            chk_point.push_back(tmp);
            c++;
            f++;
        }
    }
    chk_point.push_back(vector<Node>(1,end));

    vector<vector<pair<int,int>>> route;
    route.push_back(vector<pair<int,int>>(1,make_pair(0,0)));
    

    for(int i=1 ; i<chk_point.size(); i++){
        vector<pair<int,int>> tmp;
       
        for(int j=0; j<chk_point[i].size();j++){
            int distance;
            int prevR;
            if(chk_point[i-1].size()==1){
                distance = getDistance(chk_point[i-1][0],chk_point[i][j]);
                prevR = 0;
            }
            else{
                distance = getDistance(chk_point[i-1][0],chk_point[i][j]);
                int distance_ = getDistance(chk_point[i-1][1],chk_point[i][j]);
                prevR = (distance < distance_)? 0:1;
                distance = min(distance,distance_);
            }
            
            tmp.push_back(make_pair(distance,prevR));
            
        }
        route.push_back(tmp);

        cout << chk_point[i][tmp[0].second].x << "," << chk_point[i][tmp[0].second].y << endl;
    }

    
}




int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
    
	for(test_case = 0; test_case  < T; test_case++)
	{
        int L,S,E,A,B;
        cin >> L >> S >> E;
        Cave c(L,S,E);
        
        cin >> A;  
        c.setCel(A);
        cin >> B;
        c.setFlo(B);         
        c.setNode();
		
        Answer = 0;
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}