#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAX 25

typedef struct Block_struct{
    int num;
    int cur_addr;
    struct Block_struct *next;
    struct Block_struct *before;
}Blocks;

Blocks *list[MAX];
int total;

void init_list();
void display();
Blocks *find_node(int block_num);
void move(Blocks *node , int addr_num);
void rollback(Blocks *node);


/*
 * 傳入積木的編號
 * 找到後 回傳以指向該編號的指標
 */
Blocks *find_node(int block_num){
    int temp , check = 0;
    Blocks *ptr = NULL;
    for(temp = 0 ; temp < total ; temp++){
        ptr = list[temp];
        while(ptr != NULL){
            if(ptr->num == block_num){
                check = 1;
                break;
            }else{
                ptr = ptr->next;
            }
        }
        if(check == 1){
            break;
        }
    }
    return ptr;

}

/*
 * 傳入指向積木的指標
 * 把該積木以上的積木全部搬回原來的位置(編號1 搬回1原本的位置)
 * */
void rollback(Blocks *node){
    Blocks *ptr = node->next;
    while(ptr != NULL){
        if(ptr->num != ptr->cur_addr){
            move(ptr , ptr->num);
        }
        ptr = ptr->next;
    }
}


/*
 * 傳入要被搬動的積木指標
 * 和要被搬到哪塊積木上的位址
 * list 是全域變數 Blocs *list[MAX]
 * */
void move(Blocks *node , int addr_num){
    Blocks *ptr = list[addr_num];
    if(ptr != NULL){
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
        if(node->before != NULL){
            node->before->next = NULL;
        }else{
            list[node->cur_addr] = NULL;
        }
        node->before = ptr;
    }else{
        list[addr_num] = node;
        if(node->before != NULL){
            node->before->next = NULL;
        }
        node->before = NULL;
    }

    while(node != NULL){
        node->cur_addr = addr_num;
        node = node->next;
    }
}


void init_list(){
    int i = 0 ;
    for(i = 0 ; i < total ; i++){
        Blocks *block = (Blocks *)malloc(sizeof(Blocks));
        block->num = i;
        block->cur_addr = i;
        block->next = NULL;
        block->before = NULL;
        list[i] = block;
    }
}



void display(){
    int temp , i;
    Blocks *ptr = NULL;
    for(i = 0 ; i <total ; i++){
        printf("%d:" , i);
        ptr = list[i];
        while(ptr != NULL){
            printf(" %d" , ptr->num);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main(){
    while(scanf("%d" , &total) == 1){
        if((total >= 0) && (total < 25)){
            break;
        }
    }
    init_list();
    char act[5] , kind[5];
    int a , b , cmd;
    while(scanf("%s" , act) == 1){
        if(act[0] == 'q'){
            break;
        }else{
            scanf("%d %s %d" , &a , kind , &b);
            if((a == b ) || ((a > total) && (b > total))){
                continue;
            }
            Blocks *a_block = find_node(a);
            Blocks *b_block = find_node(b);
            if(a_block->cur_addr == b_block->cur_addr){
                continue;
            }

            if(act[0] == 'm'){
                cmd = 10;
            }else{
                cmd = 20;
            }

            if(kind[1] == 'n'){
                cmd += 1;
            }else{
                cmd += 2;
            }
            switch(cmd){
                case 11:
                    rollback(a_block);
                    rollback(b_block);
                    break;
                case 12:
                    rollback(a_block);
                    break;
                case 21:
                    rollback(b_block);
                    break;
                case 22:
                    break;
            }
            move(a_block , b_block->cur_addr);
        }
    }
    display();
    return 0;
}

