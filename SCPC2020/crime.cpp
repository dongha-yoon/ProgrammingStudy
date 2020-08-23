#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;


void operator ++()


struct Location{
    int idx_x;
    int idx_y;
    double prob;
    double dist;
    bool operator==(const Location &other) const{
        return (idx_x == other.idx_x) && (idx_y == other.idx_y);
    }
};
inline double getDistance(const Location a, const Location b){
    return pow(a.idx_x-b.idx_x,2) + pow(a.idx_y-b.idx_y,2);
}
int ccw(Location a, Location b, Location c) {
	Location ab;
	ab.idx_x = b.idx_x - a.idx_x; 
	ab.idx_y = b.idx_y - a.idx_y;
	Location bc;
	bc.idx_x = c.idx_x - b.idx_x;
	bc.idx_y = c.idx_y - b.idx_y;
	double ret = ab.idx_x*bc.idx_y - ab.idx_y*bc.idx_x;
	ret = -ret;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}
vector<Location> LocList;
vector<int> hull_indices;
vector<vector<int>> hull_indices_set;
// class Map{
//     private:
        
        
//     public:
//         static     
//         Map(int n=0){  }
//         void setMap();
//         void setHull();
//         double solve();
//         bool isOutofHull(Location a);
//         static bool sortLoc(const Location &a,const Location &b);
//         static bool sortbyTan(const Location &a,const Location &b);
//         friend int ccw(Location a, Location b, Location c);

// };
bool sortLoc(const Location &a,const Location &b){
    if(a.idx_y < b.idx_y) return true;
    else if(a.idx_y == b.idx_y)
        if(a.idx_x < b.idx_x)
            return true;
    return false;
}

bool sortbyTan(const Location &a,const Location &b){
    int ccw_val = ccw(LocList[0],a,b);
    if(ccw_val > 0) return true;
    else if(ccw_val < 0) return false;
    else// == 0
        if(a.dist < b.dist) return true;
    return false;
}

// void Map::setMap(){
    
// }
// void Map::setHull(){
    
// }
bool isOutofHull(Location a){
    for(int i=0;i<hull_indices.size();i++){
        if(LocList[hull_indices[i]]== a) return true; 
    }
    return false;
}
// double Map::solve(){
    
// }



double Answer;
int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer = 0;
        int N,K,M;
        cin >> N;
        
        int size;
        Location v_point;
        size = N;
        LocList.resize(N);
        //setMap
		for(int i=0;i<size;i++)
            scanf("%d", &LocList[i].idx_x);
        for(int i=0;i<size;i++)
            scanf("%d", &LocList[i].idx_y);
        for(int i=0;i<size;i++)
            scanf("%lf", &LocList[i].prob);

        cin >> v_point.idx_x >> v_point.idx_y;
        LocList.push_back(v_point);   
        cout << "### SET HULL ###" << endl;
        //set Hull
        sort(LocList.begin(),LocList.end(),sortLoc);
        cout << "### AFTER SORT ###" << endl;
        // int idx_count=0;
        // while(LocList.size() > 2){
            hull_indices.clear();

            for(int i=0;i<size+1;i++){
                LocList[i].dist = getDistance(LocList[0],LocList[i]);
            }
            cout << "### AFTER GET DISTANCE ###" << endl;
            sort(LocList.begin()+1,LocList.end(),sortbyTan); 
            cout << "### AFTER SORT2 ###" << endl;

            hull_indices.push_back(0);
            hull_indices.push_back(1);
            cout << "### START GET HULL ###" << endl;
            for (int i = 2; i < LocList.size(); i++) {
                while ( hull_indices.size()>=2 && ccw(LocList[hull_indices[hull_indices.size()-2]],LocList[hull_indices[hull_indices.size()-1]],LocList[i]) <= 0) hull_indices.pop_back();
                hull_indices.push_back(i);
            }
            cout << "#####" << endl;
            for(int i=0;i<hull_indices.size();i++){
                    cout <<  LocList[hull_indices[i]].idx_x << "," <<  LocList[hull_indices[i]].idx_y << endl;
            }
            // vector<Location> newLocList;
            // for(int i=0;i<hull_indices.size();i++){
            //     newLocList.push_back(LocList[hull_indices[i]]);
            // }
            // LocList = newLocList;
            cout << "### END SETTING HULL ###" << endl;
            //solve


            // idx_count += hull_indices.size();
            // hull_indices_set.push_back(hull_indices);
        // }
        if(isOutofHull(v_point)) Answer = 0;
        else{
            for(int i=0;i<LocList.size();i++){
                if(LocList[i] == v_point){
                    Answer = LocList[i].prob * LocList[i-1].prob * LocList[i+1].prob;
                }
            }
        }
    
        LocList.clear();
        hull_indices.clear();
        // Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << fixed << setprecision(6)<< Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
