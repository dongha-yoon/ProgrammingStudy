/*
# problem
https://www.codeground.org/practice/
11	SCPC 2015 Online	
Frog Leaps

#review
https://ssyoon.tistory.com/17
*/
#include <iostream>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char** argv)
{  
	int T, test_case,N,K;
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
	    Answer = 0;        
        scanf("%d",&N);

        vector<int> dist;
	    int pos=0;
        int tmp;
        int max_dist=0;
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            dist.push_back(tmp-pos);
            pos = tmp;
            max_dist = max(max_dist,dist.back());
        }
        scanf("%d",&K);
        if(max_dist > K) Answer=-1;
        else{
            int acc_dist=0; //accumulated distance
            auto i=dist.begin();
            while(i!=dist.end()){
                acc_dist+= *i;
                if(acc_dist > K){
                    Answer++;
                    acc_dist=0;
                }
                else i++;
            }
            if(acc_dist > 0) Answer++;//check if acc_dist is remain.
        }        

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}