#include<stdio.h>
#include<stdlib.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int cycle_length(int num){
    int count = 1 ;
    while(num != 1){
        if(num % 2){
            num = (num * 3) + 1;
        }else{
            num = num / 2;
        }
        count += 1;
    }
    return count;
}
int main(){
    int num1 = 0, num2 = 0 , i = 0 , bg = 0 , temp = 0;
    while(scanf("%d %d" , &num1 , &num2) == 2){
        bg = 0;
        for(i = min(num1 , num2) ; i <= max(num1 , num2) ; i++){
            temp = cycle_length(i);
            if(bg < temp){
                bg = temp;
            }
        }
        printf("%d %d %d\n" ,num1 , num2 , bg);
    }
    return 0;
}

