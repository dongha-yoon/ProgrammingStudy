/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 200'001

int pay[MAX_SIZE];
int *sum,*idx;

int Answer;

void init(int n){
    for(int i=1;i<=n;i++)
        pay[i]=0;
    delete [] sum;
    delete [] idx;
}

inline bool comp(int i,int j){
    if(sum[i] > sum[j] ) return true;
    else return false;
}

int main(int argc, char** argv)
{
	int T, test_case;
	

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer = 0;
        int N,K,Q;
		cin >> N >> K >> Q;
        
        int s_size = N-K+2;
        sum = new int[s_size];
        idx = new int[s_size];

        for(int i=1;i<=N;i++){
            if(i<s_size) idx[i]=i;
            scanf("%d",&pay[i]);
            for(int j=i;j<i+K;j++){
                sum[j] = pay[i];
            }
        }

        sort(idx+1,idx+s_size,comp);
        cout << "Case #" << test_case+1 << endl;
        cout << sum[(s_size+1)/2] << " ";

        for(int i=0;i<Q;i++){
            int input1,input2;
            scanf("%d %d",&input1,&input2);
            sum[input1] = input2;
            sort(idx+1,idx+s_size,comp);
            cout << sum[(s_size+1)/2] << " ";
        }

        
		// Print the answer to standard output(screen).
		
		cout << endl;
        init(N);
	}

	return 0;//Your program should return 0 on normal termination.
}