/*
# problem
https://www.codeground.org/practice/
76	SCPC 2018 Online	
Space Station

#review
https://ssyoon.tistory.com/18
*/
#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

class Module{
    private:
        map<int,vector<int>> Node;
    public:
        void setNode();    
        void addNode(int a,int b);
        int split();
        inline bool isConnected(const int& n1,const int& n2);

};

void Module::setNode(){
    int N,L;
    scanf("%d %d",&N,&L);
    for(int i=0;i<L;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        addNode(a,b);
        addNode(b,a);
    }
    // for(auto i = Node.begin();i!=Node.end();i++){
    //     cout << (i->first) << "-> ";
    //     for(auto j = (i->second).begin(); j!=(i->second).end();j++)
    //         cout << *j << ", ";
    //     cout << endl;
    // } 
    // cout << endl;
}

void Module::addNode(int a,int b){
    if(Node.find(a) == Node.end()){
        vector<int> tmp;
        tmp.push_back(b);
        Node.insert(make_pair(a,tmp));
    }
    else{
        (Node.find(a)->second).push_back(b);
    }
}


int Module::split(){
    bool flag = false;
    int er_key=0;
    while(!flag){
        for(auto i = Node.begin();i!=Node.end();i++){
            if( i->second.size() == 2 && isConnected(i->second[0],i->second[1])){
                er_key = i->first;
                flag = false;
                break;
            }
            flag = true;
        }
        if(!flag)   Node.erase(er_key);
    }
    return Node.size();
}

inline bool Module::isConnected(const int& n1,const int& n2){
    if(Node.find(n1)==Node.end()
       || Node.find(n2)==Node.end()) return false;
    else{
        vector<int>& vec1(Node.find(n1)->second);
        vector<int>& vec2(Node.find(n2)->second);
        
        for(auto i=vec1.begin();i!=vec1.end();i++){
            if(*i==n2){
                return true;
            }
        }
    }
    return false;
}



int Answer;
int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Module station;
        station.setNode();
        Answer = station.split();

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}