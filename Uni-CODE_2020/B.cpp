#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;



int main(){
    
    string input;
    cin >> input;
    int SIZE = input.size();

    int count =0;
    for(int i=0 ;i<SIZE; i++){
        if(input[i]=='1')
            count++;
    }


    int r_count=0;
    int z_count=0;
    bool z_flag = 0;
    int idx = 0;
    for(int i=0 ;i<SIZE; i++){
        idx=i;
        if(input[i]=='0')
            z_count++;
        else if(input[i]=='1')
            r_count++;
        if(r_count==count/2)
            break;
        if(z_count==(SIZE-count)/2){
            z_flag=1;
        }
    }
    
    string output;
    int cond = (z_flag)?(SIZE-count)/2:z_count;
    for(int i=0;i<cond;i++)
        output+="0";
    
    while(r_count!=count){
        idx++;

        if(input[idx]=='0'){
            if(!z_flag){
                output+="0";
                z_count++;
            }
            if(z_count==(SIZE-count)/2){
                z_flag=1;
            }
        }
        if(input[idx]=='1'){
            r_count++;
            output+="1";
        }
            
            
    }
    for(z_count;z_count<(SIZE-count)/2;z_count++)
        output+="0";

    cout << output;

}