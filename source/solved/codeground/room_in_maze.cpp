/*
# problem
https://www.codeground.org/practice/
6	Practice	
Room in Maze

#review

*/
#include <iostream>

using namespace std;

unsigned long long int Answer;
int N,K;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 1;
		cin >> N >> K;
		
        //get largeset value of each group sequence element
		int *end_num = new int[2*N];
		end_num[0]=0; //virtual value
		for(int i=1;i<=N;i++)
		    end_num[i]=end_num[i-1]+i;
        for(int i=N+1;i<2*N;i++)
		    end_num[i]=end_num[i-1]+(2*N-i);


		int ind_d=1,ind_i=1; // set starting index.
		
		string move;
        cin >> move;

		for(int i=0;i<K;i++){
		    if(move[i]=='U'){
		        if(ind_d<=N)ind_i--;
		        ind_d--;
		    }
		    else if(move[i]=='D'){
		        
		        if(ind_d<N)ind_i++;
		        ind_d++;
		    }
		    else if(move[i]=='L'){        
		        if(ind_d>N)ind_i++;
		        ind_d--;
		    }
		    else{ // move[i]=='R'
		        if(ind_d>=N)ind_i--;
		        ind_d++;
		    }
		    
		    int val;
            if(ind_d<=N){
                if(ind_d%2)
                    val=end_num[ind_d]-ind_i+1;
                else
                    val=end_num[ind_d]-(ind_d-ind_i);
            }
            else{
                if(ind_d%2)
                val=end_num[ind_d]-ind_i+1;
                else
                val=end_num[ind_d]-(( 2*N-ind_d)-ind_i);    
            }
            Answer+=val;
            
            // cout << "d= " << ind_d << " i= " << ind_i << endl;
            // cout << "end = " << end_num[ind_d]<< endl;
            // cout << "val = " << val << endl;
            // cout << "Ans = " << Answer << endl << endl;
            
            
		}
		
		
		
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}