#include <iostream>
#include <vector>

using namespace std;
bool isPalindrome(unsigned int N){
    vector<int> digits;
    int size;
    while(N>0){
        digits.push_back(N%10);
        N/=10;
    }
    size = digits.size();
    for(int i=0;i<size/2.0; i++)
        if(digits[i]!=digits[size-i-1])
            return false;
    return true;    
}

unsigned int getPalindrome(unsigned int N){
    while(!isPalindrome(N--)){}
    return N+1;
}
int main(int argc, char** argv)
{
	int T, test_case;
    unsigned int N;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{   
	    int count=0;
        vector<unsigned int> answer;
        cin >> N;
        while(true){
            unsigned int pal = getPalindrome(N);
            if(pal<1)
                break;
            N-=pal;
            answer.push_back(pal);
            count++;
        }
		
		cout << "Case #" << test_case+1 << endl;
		cout << count << " ";
		if(count){
		    for(int i=0;i<answer.size();i++)
		        cout << answer[i]<< " ";
		}
        cout << endl;
	}
	return 0;
}
