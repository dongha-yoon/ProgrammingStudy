/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

int Answer;

#define MAX 50001

char B[MAX];
char ans[MAX];
char ZERO[MAX];

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
    for(int i=0;i<MAX;i++)
        ZERO[i]='x';

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        int n,t;
        scanf("%d %d",&n, &t);
        scanf("%s",B);
        
        memcpy(ans,ZERO,n);
        int cp_size = min(t,n-t);
        memcpy(ans+t,B,cp_size);
        memcpy(ans+n-t-t,B+n-t,cp_size);

        for(int i=t; i<n-t;i++){
            if(B[i] == '0')
                ans[i+t] = ans[i-t] = '0';
                
            if(ans[i]=='x')
                if(B[i-t]== B[i+t])
                    ans[i] = B[i-t];

        }
        for(int i=n-t; i<n;i++){        
            if(ans[i]=='x'){
                if(i-2*t >=0 && ans[i-2*t] != B[i-t])
                    ans[i] = B[i-t];
                else
                    ans[i] = '0';
            }        
        }
        for(int i=0; i<t;i++){
            if(ans[i]=='x'){
                if(i+2*t < n && ans[i+2*t] != B[i+t])
                    ans[i] = B[i+t];
                else
                    ans[i] = '0';
            }        
        }


        
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}