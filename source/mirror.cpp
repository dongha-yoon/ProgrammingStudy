/*
# problem
https://www.codeground.org/practice/
12	SCPC 2015 Online	
Mirror in the Room

#review
https://ssyoon.tistory.com/16
*/
#include <iostream>

using namespace std;

struct Mirror{
    char mode;
    bool isVisited;
    Mirror(char m='0', bool b=false){mode=m; isVisited=b;}
};

class Room{
    private:
        Mirror** mirror;
        int size;
    public:
        Room(int n=1);
        void setMirror();
        int shootLight();
        inline bool isOut(const pair<int,int> p);
};

Room::Room(int n){
    size = n;
    mirror = new Mirror*[n];
    for(int i=0;i<n;i++)
        mirror[i] = new Mirror[n];
}

void Room::setMirror(){
    for(int i=0;i<size;i++){
        string tmp;
        cin >> tmp;
        for(int j=0;j<size;j++){
            mirror[i][j].mode = tmp[j];
        }
    }
}

int Room::shootLight(){
    int res = 0;

    pair<int,int> pos(0,0);
    int dir_x = 1; // Left=-1, Right=1, No=0
    int dir_y = 0; // Up=-1, Down=1, No=0

    while(!isOut(pos)){
        Mirror& m = mirror[pos.first][pos.second];
        printf("position is (%d,%d), Mode is %c\n", pos.first,pos.second, m.mode);

        if(!m.isVisited && m.mode!='0'){
            res++;
            m.isVisited = true;
        }

        if(m.mode == '0'){
            //direction is not change!
        }
        else if(m.mode == '1' ){
            int swap = dir_x;
            dir_x = -dir_y;
            dir_y = -swap;
        }
        else{// m.mode == '2'
            int swap = dir_x;
            dir_x = dir_y;
            dir_y = swap;
        }
        pos.first += dir_y;
        pos.second += dir_x;
    }
    return res;
}

inline bool Room::isOut(const pair<int,int> p){
    if(p.first < 0 || p.first >=size || p.second <0 || p.second >=size){
        printf("It's out of room! (%d,%d)\n",p.first,p.second);
        return true;
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
        int N;
        scanf("%d",&N);
        Room mirrorRoom(N);
        mirrorRoom.setMirror();
        Answer = mirrorRoom.shootLight();

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}