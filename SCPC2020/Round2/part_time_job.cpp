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
int sum[MAX_SIZE];
int idx[MAX_SIZE];

int Answer;

void init(int n){
    for(int i=1;i<=n;i++){
        pay[i]=sum[i]=idx[i]=0;
    }
      
}

inline bool comp(int i,int j){
    if(sum[i] < sum[j] ) return true;
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

        for(int i=1;i<=N;i++){
            if(i<s_size) idx[i]=i;
            scanf("%d",&pay[i]);
            for(int j=i-K+1;j<=i;j++){
                if(j<1) continue;
                sum[j] += pay[i];
            }
        }

        sort(idx+1,idx+s_size,comp);
        // for(int i=1;i<s_size;i++){
        //     cout << sum[i] << " | " << sum[idx[i]] << endl;
        // }
        int med_idx = (s_size+1)/2;
        cout << "Case #" << test_case+1 << endl;
        cout << sum[idx[med_idx]] << " ";

        for(int i=0;i<Q;i++){
            int input1,input2;
            scanf("%d %d",&input1,&input2);
            for(int j=input1-K+1;j<=input1;j++){
                sum[j] += input2-pay[input1];
            }
            pay[input1] = input2;

            int start = max(1,med_idx-K);
            int end = min(s_size,med_idx+K);
            sort(idx+start,idx+end,comp);

            cout << sum[idx[med_idx]] << " ";
        }

        
        // Print the answer to standard output(screen).
        
        cout << endl;
        init(N);

	}

	return 0;//Your program should return 0 on normal termination.
}
