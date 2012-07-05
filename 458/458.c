#include <stdio.h>
#include <string.h>
int main(){
    char str[10000];
    while(scanf("%s" , str) == 1){
        int tmp = 0;
        int len = strlen(str);
        while(tmp < len){
            printf("%c",str[tmp]-7);
            tmp += 1;
        }
        printf("\n");
    }
    return 0;
}
