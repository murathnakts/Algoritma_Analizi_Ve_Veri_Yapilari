#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 4

struct stack {
    int data[STACK_SIZE];
    int top;
};

void push(struct stack *stk,int data){
    if(stk->top == STACK_SIZE -1){
        printf("Stack Dolu\n\n");
        return;
    } else {
        stk->top ++;
        stk->data[stk->top] = data;
    }
    printf("\n");
}

int pop(struct stack *stk){
    if(stk->top == STACK_SIZE-1){
        printf("Stack Dolu");
        return;
    } else {
        int x = stk->top--;
        return x;
    }

}

void reset(struct stack *stk){
    stk->top = -1;
}

void print_stack(struct stack *stk){
     if(stk->top == -1){
        printf("Stack Dolu");
        return;
    }
    int temp = stk->top;
    do{
        printf("%d ",stk->data[temp]);
        temp--;
    }while(temp!=-1);
}

int main()
{   int secim,data;
    struct stack stk;
    stk.top = -1;

    while(1){
    printf("1-Stacke Eleman Ekle (PUSH)\n");
    printf("2-Stackdan Eleman Cikarma (POP)\n");
    printf("3-Stacki Bosaltma (RESET) \n");
    printf("4-Stacki Listele\n");
    printf("5-Cikis\n");
    printf("Seciminiz...\n");
    scanf("%d", &secim);

    switch(secim){
    case 1:
        printf("\nEklemek Istediginiz Deger: ");
        scanf("%d", &data);
        push(&stk, data);
        break;
    case 2:
        data=pop(&stk);
        break;
    case 3:
        reset(&stk);
        break;
    case 4:
        print_stack(&stk);
        break;
    case 5:
        exit(0);
        break;


    }
}
}
