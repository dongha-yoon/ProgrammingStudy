/*
https://www.codeground.org/practice/
2	Practice	
Programming Contest
*/

#include <iostream>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	
	for(test_case = 0; test_case  < T; test_case++)
	{
        int max,num;
        max=0;

		cin >> num;
		int score[num];
		Answer = num;
        for(int i=0;i<num;i++){
            cin >> score[i];
        }
        sort(score,score+num);
        
        for(int i=0,j=num;i<num;i++,j--)
            if(max<score[i]+j)
                    max=score[i]+j;
                    
        for(int i=0;i<num;i++){
            if( (score[i]+num) < max )
                Answer--;
        }
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}