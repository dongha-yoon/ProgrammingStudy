#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)calloc(prices_len,sizeof(int));
    bool* flag = (bool*)calloc(prices_len,sizeof(bool));

    for(int i=1;i<prices_len;i++){
        for(int j=0;j<i;j++){
            if(!flag[j]){
                answer[j]++;
                if(prices[i]<prices[j])
                    flag[j]=true;
            }
        }
    }
    return answer;
}
int main(){

    int p[5] = {1,2,3,2,3};//,3,2,1};
    size_t size = 5;

    int *a = solution(p,size);
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
}
