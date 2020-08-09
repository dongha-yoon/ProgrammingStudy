/*
https://www.codeground.org/practice/
100	SCPC 2019 Online	
Drone exploration
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;

struct Node{
    int x,y;
    Node(int a,int b){ x=a; y=b;}
}
struct T_B{
    int w,h;
    T_B(int a,int b){ w=a; h=b;}
}


class Cave{
    private:
        Node start,
              end;
        vector<Node> chk_point;
        vector<T_B> cel;
        vector<T_B> flo; 
    public:
        Cave(int L,int S,int E);
        void setCel(int N);
        void setFlo(int N);
        void setNode();
        
};

Cave::Cave(int L,int S,int E){
    start = Node(0,S);
    end = Node(L,E);
}
void Cave::setCel(int N){
    for(int i=0;i<N,i++){
            int a,b;
            cin >> a >> b;
            cel.push_back(T_B(a,b));
        }
}
void Cave::setFlo(int N){
    for(int i=0;i<N,i++){
            int a,b;
            cin >> a >> b;
            flo.push_back(T_B(a,b));
        }
}
void Cave::setNode(){
    int c_x =0,
        f_x =0;
    vector<T_B>::iterator c = cel.begin(),
                          f = flo.begin();
    while(!(c==cel.end() && f==flo.end())){
        if( (c_x + (*c).w) < (f_x + (*f).w)){
            c_x += (*c).w;
            chk_point.push_back(Node(c_x, min((*c).h,*(c+1).h)) );
            c++;
        }
        else if( (c_x + (*c).w) > (f_x + (*f).w)){
            f_x += (*f).w;
            chk_point.push_back(Node(f_x, max((*f).h,*(f+1).h)) );
            f++;
        }
        else{ //if equal
            c_x += (*c).w;
            f_x += (*f).w;
            chk_point.push_back(Node(c_x, min((*c).h,*(c+1).h)) );
            chk_point.push_back(Node(f_x, max((*f).h,*(f+1).h)) );
            c++;
            f++;
        }
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
        
		
        Answer = 0;
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}