/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class strUtils{
    private:
        string str;
        int N,K,M;
    public:
        strUtils(int n=0,int k=0,int m=0);
        void getstr(){ cin >> str;}
        int getMax(string str);
        vector<int> getSubs(string str);
        int solve();
};
strUtils::strUtils(int n,int k,int m){
    N=n;
    K=k;
    M=m;
}

int strUtils::getMax(string str){
    // cout << "str : " << str << endl;
    vector<int> number_set = getSubs(str);
    int max=0;
    for(int i=0;i<number_set.size();i++){
        int count=0;
        for(int j=i;j<number_set.size();j++){
            // cout << number_set[i] << " | " << number_set[j] <<endl;
            if( (number_set[j]-number_set[i]) <= M) count++;
            else break;
        }
        // cout << "count : " << count << endl;
        if(max < count ) max = count;
    }
    return max;
}
vector<int> strUtils::getSubs(string str){
    vector<int> r;
    for(int i=0;i<str.size()-K+1;i++){
        // cout << stoi(str.substr(i,K)) << endl;
        r.push_back( atoi(str.substr(i,K).c_str()) );
    }
    sort(r.begin(),r.end());
    return r;
}

int strUtils::solve(){
    int maximum=0;    
    for(int i=0;i<str.size();i++){
        string tmp = str;
        if(tmp[i]!='1') tmp[i]='1';
        else continue;
        maximum = max(maximum, getMax(tmp));
    }
    return maximum;
}

int Answer;
int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer = 0;
        int N,K,M;
        cin >> N >> K >> M;
        strUtils str(N,K,M);
        str.getstr();
        Answer = str.solve();


		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}


