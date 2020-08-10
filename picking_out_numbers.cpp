/*
https://www.codeground.org/practice/
1	Practice	
Picking Out Numbers
*/
#include <iostream>
#include <map>

using namespace std;

unsigned int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
    	Answer = 0;
        map<unsigned int,bool> m;

		int N;
		cin >> N;
	
		for(int i=0;i<N;i++){
	        unsigned int temp;
	        cin >> temp;
	        if(m.find(temp)==m.end())
                m.insert(make_pair(temp,1));
            else
                m.erase(temp);       
		}  

        for(auto i=begin(m); i!=end(m); i++)
            Answer ^= i->first;

	
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}