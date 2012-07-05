#include <stdio.h>
#define RULE_MAX 6
int main(){
    char str[6][3] = {"BCG" , "BGC" , "CBG" , "CGB" , "GBC" , "GCB"};
    int rule[6][6] = {{3 , 6 , 2 , 8 , 1 , 4 },
                      {3 , 6 , 1 , 7 , 2 , 5 },
                      {5 , 8 , 0 , 6 , 1 , 4 },
                      {5 , 8 , 1 , 7 , 0 , 3 },
                      {4 , 7 , 0 , 6 , 2 , 5 },
                      {4 , 7 , 2 , 8 , 0 , 3 }};
    int qes[9];
    while(scanf("%d %d %d %d %d %d %d %d %d" ,  &qes[0] , &qes[1] , &qes[2] ,
                &qes[3] , &qes[4] , &qes[5] ,
                &qes[6] , &qes[7] , &qes[8] )!= EOF){
        char *ans_str;
        int ans_min = -1;
        int tmp1 = 0;
        for(tmp1 = 0 ; tmp1 < RULE_MAX ; tmp1++){
            int tmp2 = 0;
            int check = 0;
            int flag = 0;
            for(tmp2 = 0 ; tmp2 < RULE_MAX; tmp2++){
                check += qes[rule[tmp1][tmp2]];
            }
            if(ans_min == -1){
                ans_min = check;
                ans_str = str[tmp1];
            }else if(check < ans_min){
                ans_min = check;
                ans_str = str[tmp1];
            }
        }
        printf("%c%c%c %d\n",*(ans_str + 0) , *(ans_str + 1) ,*(ans_str + 2) ,ans_min);
    }
    return 0;
}
