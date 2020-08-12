#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
    int seed;
    cout << "Enter Seed : ";
    cin >> seed;

    int num;
    cout << "How many to Generate? : ";
    cin >> num;

    srand(seed);
    for(int i=0; i<num; i++) cout << (rand()%100 +1) << " ";
}