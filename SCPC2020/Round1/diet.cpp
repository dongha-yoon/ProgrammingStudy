#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer=0;
        //input.
        int N,K;
        scanf("%d %d",&N,&K);
        vector<int> lunch;
        vector<int> dinner;

        int tmp;
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            lunch.push_back(tmp);
        }
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            dinner.push_back(tmp);
        }
        sort(lunch.begin(),lunch.end());
        sort(dinner.begin(),dinner.end());
        
        // cout << "\tlunch | dinner" << endl;
        // for(int i=0;i<N;i++){
        //     cout << i << ":\t" << lunch[i] <<"  |  " << dinner[i] << endl;
        // }
        if(K < N){
            lunch.resize(K);
            dinner.resize(K);
        }
        for(int i=0;i<K;i++){
            int sum = lunch[i] + dinner[K-1-i];
            if(sum > Answer)
                Answer=sum;
        }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
