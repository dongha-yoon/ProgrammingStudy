/*
https://programmers.co.kr/learn/courses/30/lessons/42860
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//A-Z : ASCII 65-90
int continueA(string name, int &idx){
    int cnt = 0;
    int result = 0;
    idx = -1;
    for(int i=0; i<name.size();i++){
        if(name[i]=='A') cnt++;
        else{
            if(cnt > result) idx=i-1;
            result = max(cnt,result);
            cnt =0;
        }
    }
    return result;
}

int moveX(string name){
    int move = 0;
    int move_r = 0;
    int move_z = 0;

    int contAidx;
    int contA = continueA(name, contAidx);
    int z_part1 = contAidx - contA;
    int z_part2 = name.size()-(contAidx+1);

    move_z = z_part1 + z_part2 + min(z_part1,z_part2);

    for(int i=1;i<name.size();i++){
        move_r = name.size() - i;
        if(name[i]!='A') break;
        if(name[name.size()-i]!='A') move = name.size() - i;
    }
    
    for(int i=1;i<name.size();i++){
        move = name.size() - i;
        if(name[name.size()-i]!='A') break;
    }

    // return smallest movement.
    int min = 10000000;
    if(move < min)  min = move;
    if(move_r < min)  min = move_r;
    if(move_z < min)  min = move_z;
    
    return min;
}

int moveY(char a){
    if( a > 'N') return int('Z' - a) + 1;
    else return int(a - 'A');
}

int solution(string name) {
    int answer = 0;    
    answer += moveX(name);
    // cout << "Move X : " << answer << endl;
    for(int i=0;i<name.size();i++)
        answer += moveY(name[i]);
    
    return answer;
}

int main(){
    cout << "enter please(exit : -1)" << endl;
    string str;
    do{
        cin >> str;
        cout << str << " : " << solution(str) << endl;
    }while(str !="-1");
}