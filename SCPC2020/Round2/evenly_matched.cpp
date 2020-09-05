/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

unordered_map<int,int> A;
unordered_map<int,int> B;

vector<int> vec_A;
vector<int> vec_B;



inline void insert(int n,unordered_map<int,int>& M){
    if(M.find(n)==M.end())
        M[n]=1;
    else
        M[n]++;
}

void init(){
    A.clear();
    B.clear();
    vec_A.clear();
    vec_B.clear();
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case = 0; test_case  < T; test_case++)
	{
        init();
        
        int Answer = 0;
        int N;
        cin >> N;

        int tmp;
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            insert(tmp,A);
        }
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            if(A.find(tmp)!=A.end()){
                if(A[tmp] > 1){
                    A[tmp]--;
                    continue;
                }
                else if(A[tmp]==1){
                    A.erase(tmp);
                    continue;
                }
            }
            insert(tmp,B);
        }



        for(auto i : A){
            // cout << i.first << "," << i.second << " ";
            for(int j=0;j<i.second;j++)
                vec_A.push_back(i.first);
        }
        // cout << endl;
        for(auto i : B){
            // cout << i.first << "," << i.second << " ";
            for(int j=0;j<i.second;j++)
                vec_B.push_back(i.first);
        }
        // cout << endl;
        sort(vec_A.begin(),vec_A.end());
        sort(vec_B.begin(),vec_B.end());

        int max_gap = 0;
        int size = vec_A.size();
        // cout << vec_A.size() << " " << vec_B.size() << endl;

        for(int i=0;i<size;i++){
            int gap = abs(vec_A[i]-vec_B[i]);
            if(max_gap < gap) max_gap = gap;
            Answer += gap;
        }
        Answer -= max_gap;
    
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}