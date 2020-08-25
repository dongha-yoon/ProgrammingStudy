/*
# problem
https://www.codeground.org/practice/
3	Practice	
Studying for Exams

# review
https://ssyoon.tistory.com/14?category=922628
*/

#include <iostream>
#include <algorithm>
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
		
	    int* arr= new int [N];
	    
		for(int i=0;i<N;i++)cin >> arr[i];
		sort(arr,arr+N);
		for(int i=0;i<K;i++)Answer+=arr[N-1-i];
		
		delete[] arr;
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
		
		timer.calculate();
	}

	return 0;//Your program should return 0 on normal termination.
}

/*
Using scanf/printf 

int main(int argc, char** argv)
{
// 	RuntimeClock timer;
    int T, test_case;
	scanf("%d",&T);//cin >> T;
	
    int N,K,temp;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		scanf("%d",&N);//cin >> N >> K;
		scanf("%d",&K);
	    int* arr= new int [N];
	    
		for(int i=0;i<N;i++)scanf("%d",&arr[i]);//cin >> arr[i];
		sort(arr,arr+N);
		for(int i=0;i<K;i++)Answer+=arr[N-1-i];
		
		delete[] arr;
		// Print the answer to standard output(screen).
        printf("Case #%d\n",test_case+1);
        printf("%d\n",Answer);
// 		cout << "Case #" << test_case+1 << endl;
// 		cout << Answer << endl;
		
// 		timer.calculate();
	}

	return 0;//Your program should return 0 on normal termination.
}


*/