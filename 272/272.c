#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    int flag = 0;
    while(gets(str)){
        int len = strlen(str);
        int tmp = 0;
        while(tmp < len){
            if((str[tmp] == '"') && (flag == 0)){
                printf("``");
                flag = 1;
            }else if((str[tmp] == '"') && (flag == 1)){
                printf("''");
                flag = 0;
            }else{
                printf("%c" , str[tmp]);
            }
            tmp += 1;
        }
        printf("\n");
    }
    return 0;
}
