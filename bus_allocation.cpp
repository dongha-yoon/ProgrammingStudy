/*
https://www.codeground.org/practice/
74	SCPC 2018 Online	
Bus Allocation
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "headers/runtime.h"


using namespace std;

int main(int argc, char** argv)
{
    RuntimeClock clock;
    int T, test_case,N,K,S,M,Answer;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;
        cin >> K;
        vector<int> score;
        vector<int> bus_max;

        //input score
        int tmp;
        for(int i=0;i<N;i++){
            cin >> tmp;
            score.push_back(tmp);
        } 

        sort(score.begin(),score.end());           

        bus_max.push_back(score[0]);
        for (int i=1;i<N;i++){
            vector<int>::iterator iter;
            bool isAllocated=false;
            for(iter=bus_max.begin(); iter!=bus_max.end(); iter++){
                if(score[i]-*iter <= K) continue;
                else{
                    *iter = score[i];
                    isAllocated = true;
                }
            }
            if(!isAllocated) bus_max.push_back(score[i]);
        }
        
		Answer = bus_max.size();
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

        cout << "Total Runtime : " << clock.get_time() << endl;
	return 0;
}