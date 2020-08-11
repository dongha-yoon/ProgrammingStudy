/*
https://www.codeground.org/practice/
3	Practice	
Studying for Exams
*/

#include <iostream>
#include <list>
#include "headers/runtime.h"

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	RuntimeClock timer;
    int T, test_case;
	cin >> T;
    int N,K,temp;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		cin >> N >> K;
		
		int max = 101;
		int min = 0;

		list<int> score;
		for(int i=0;i<N;i++){
			int v;
			cin >> v;
			if( score.size() < K){
				score.push_back(v);
				Answer += v;
			}
			else if( v > min && v <max ){//+ if score.size() == K (max_size)
				Answer += v;
				Answer -= score.front();
				score.push_back(v);
				score.pop_front();
			}
			score.sort();
			max = score.back();
			min = score.front();
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
		timer.calculate();
	}

	return 0;//Your program should return 0 on normal termination.
}