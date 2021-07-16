#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <list>

#define MAX 1000

using namespace std;

int deleteStack[MAX];
string solution(int n, int k, vector<string> cmd);

typedef list<int>::iterator cursor_t;

int main(){
    vector<string> cmd;
    cmd.push_back("D 2");
    cmd.push_back("C");
    cmd.push_back("U 3");
    cmd.push_back("C");
    cmd.push_back("D 3");
    cmd.push_back("C");
    cmd.push_back("Z");
    cmd.push_back("Z");
    cmd.push_back("U 2");
    solution(8,2,cmd);

    // cout << solution(10,0,cmd) << endl;
}




string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    list<int> idx;
    for(int i=0;i<n;i++)
        idx.push_back(i);
    
    // int deleteStack[n];
    list<int> stack;
    cursor_t cursor = idx.begin();
    for(int i=0;i<k;i++)
        cursor++;
    
    
    int val = 0;
    for(int i=0;i<cmd.size();i++){
        char command = cmd[i][0];
        
        if(command=='U')
            val -= stoi((cmd[i].substr(2,-1)));    
        else if(command=='D')    
            val += stoi((cmd[i].substr(2,-1)));    
        else{
            // int count = 0;
            // while(count<abs(val)){
            //     cursor += (val<0)? -1:1;
            //     if(answer[cursor]=='X')
            //         continue;
            //     count++;
            // }
            for(int i=0;i<val;i++)
                cursor++;
            
            val = 0;
            
            if(command=='C'){
                stack.push_back(*cursor);
                cursor_t next = cursor;
                next++;
                idx.erase(cursor);
                cursor = next;
                
                // int count = 0;
                // if(cursor>=n-1){
                //     while(count<1){
                //             cursor--;
                //             if(answer[cursor]=='X')
                //                 continue;
                //             count++;
                //         }  
                // }
                // else{
                //     while(count<1){
                //         cursor++;
                //         if(answer[cursor]=='X')
                //             continue;
                //         count++;
                //     }  
                // }
                if(cursor==idx.end())
                    cursor--;
            }
            else if(command=='Z'){
                cursor_t iter = idx.begin();
                while(*iter < stack.back())
                    iter++;
                idx.insert(iter,stack.back());
                stack.pop_back();
            }
        }
        for(cursor_t iter=idx.begin();iter!=idx.end();iter++)
            cout << *iter << " ";
        cout << endl;

        for(cursor_t iter=stack.begin();iter!=stack.end();iter++)
            cout << *iter << " ";
        cout << endl;
    }
    for(cursor_t iter=idx.begin();iter!=idx.end();iter++)
        answer[*iter] = 'O';
    return answer;
}